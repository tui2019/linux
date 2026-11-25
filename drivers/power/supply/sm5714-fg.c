// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2024, map220v <map220v300@gmail.com>
 */

#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/pm.h>
#include <linux/power_supply.h>
#include <linux/workqueue.h>

#define SM5714_FG_REG_DEVICE_ID		0x00
#define SM5714_FG_REG_CTRL		0x01
#define SM5714_FG_REG_INTFG		0x02
#define SM5714_FG_REG_STATUS		0x03
#define SM5714_FG_REG_INTFG_MASK	0x04
#define SM5714_FG_REG_SYSTEM_STATUS	0x10
#define SM5714_FG_REG_AUX_STAT		0x22

#define SM5714_FG_REG_SRAM_PROT		0x8B
#define SM5714_FG_REG_SRAM_RADDR	0x8C
#define SM5714_FG_REG_SRAM_RDATA	0x8D
#define SM5714_FG_REG_SRAM_WADDR	0x8E
#define SM5714_FG_REG_SRAM_WDATA	0x8F

#define SM5714_FG_ADDR_SRAM_SOC		0x00
#define SM5714_FG_ADDR_SRAM_OCV		0x01
#define SM5714_FG_ADDR_SRAM_VBAT	0x03
#define SM5714_FG_ADDR_SRAM_VSYS	0x04
#define SM5714_FG_ADDR_SRAM_CURRENT	0x05
#define SM5714_FG_ADDR_SRAM_TEMPERATURE	0x07
#define SM5714_FG_ADDR_SRAM_VBAT_AVG	0x08
#define SM5714_FG_ADDR_SRAM_CURRENT_AVG	0x09
#define SM5714_FG_ADDR_SRAM_STATE	0x15

#define SM5714_FG_POLL_MS		10000

/*
 * Samsung health HAL (vendor.samsung.hardware.health-service) reads
 * /sys/class/power_supply/<battery>/online as SEC_BATTERY_CABLE_*:
 * 0 = UNKNOWN (triggers One UI "incompatible charger" + 0% icon),
 * 1 = NONE (discharging), 4 = USB.
 */
#define SEC_BATTERY_CABLE_NONE		1
#define SEC_BATTERY_CABLE_USB		4

struct sm5714_fg {
	struct power_supply *psy;
	struct i2c_client *i2c;
	struct mutex lock;
	struct delayed_work poll_work;
	int last_capacity;
	int last_status;
	int last_voltage_mv;
	int last_temp;
};

static enum power_supply_property sm5714_fg_props[] = {
	POWER_SUPPLY_PROP_PRESENT,
	POWER_SUPPLY_PROP_ONLINE,
	POWER_SUPPLY_PROP_STATUS,
	POWER_SUPPLY_PROP_HEALTH,
	POWER_SUPPLY_PROP_TECHNOLOGY,
	POWER_SUPPLY_PROP_TEMP,
	POWER_SUPPLY_PROP_CAPACITY,
	POWER_SUPPLY_PROP_VOLTAGE_NOW,
	POWER_SUPPLY_PROP_VOLTAGE_OCV,
	POWER_SUPPLY_PROP_CURRENT_NOW,
};

static int sm5714_fg_read_sram(struct sm5714_fg *drv, u16 addr)
{
	int ret;

	mutex_lock(&drv->lock);
	ret = i2c_smbus_write_word_data(drv->i2c, SM5714_FG_REG_SRAM_RADDR, addr);
	if (ret >= 0)
		ret = i2c_smbus_read_word_data(drv->i2c, SM5714_FG_REG_SRAM_RDATA);
	mutex_unlock(&drv->lock);

	return ret;
}

static int sm5714_fg_get_status(int *status)
{
	union power_supply_propval val;
	struct power_supply *psy;
	int ret = -EINVAL;

	psy = power_supply_get_by_name("sm5714_charger");
	if (!psy)
		return ret;

	ret = power_supply_get_property(psy, POWER_SUPPLY_PROP_STATUS, &val);
	power_supply_put(psy);
	if (ret)
		return ret;

	*status = val.intval;
	return 0;
}

static int sm5714_fg_read_capacity(struct sm5714_fg *drv, int *cap)
{
	int raw = sm5714_fg_read_sram(drv, SM5714_FG_ADDR_SRAM_SOC);

	if (raw < 0)
		return raw;

	*cap = clamp_val(((raw * 10) >> 8) / 10, 0, 100);
	return 0;
}

static int sm5714_fg_read_vbat_mv(struct sm5714_fg *drv, int *vbat_mv)
{
	int raw = sm5714_fg_read_sram(drv, SM5714_FG_ADDR_SRAM_VBAT);

	if (raw < 0)
		return raw;

	if (raw & 0x8000)
		*vbat_mv = 2700 - (((raw & 0x7fff) * 10) / 109);
	else
		*vbat_mv = ((raw * 10) / 109) + 2700;

	return 0;
}

static int sm5714_fg_read_ocv_mv(struct sm5714_fg *drv, int *ocv_mv)
{
	int raw = sm5714_fg_read_sram(drv, SM5714_FG_ADDR_SRAM_OCV);

	if (raw < 0)
		return raw;

	*ocv_mv = (raw * 1000) >> 11;
	return 0;
}

static int sm5714_fg_read_current_ua(struct sm5714_fg *drv, int *curr_ua)
{
	int raw, s_stat, a_stat, curr_ma;

	raw = sm5714_fg_read_sram(drv, SM5714_FG_ADDR_SRAM_CURRENT);
	if (raw < 0)
		return raw;

	mutex_lock(&drv->lock);
	s_stat = i2c_smbus_read_word_data(drv->i2c, SM5714_FG_REG_SYSTEM_STATUS);
	a_stat = i2c_smbus_read_word_data(drv->i2c, SM5714_FG_REG_AUX_STAT);
	mutex_unlock(&drv->lock);

	curr_ma = ((raw & 0x7fff) * 1000) / 2044;
	if (raw & 0x8000)
		curr_ma = -curr_ma;

	if (a_stat >= 0 && (a_stat & 0x0400))
		curr_ma = (curr_ma * 25) / 10;

	if (s_stat >= 0 && (s_stat & 0x8000))
		curr_ma = 0;

	*curr_ua = curr_ma * 1000;
	return 0;
}

static int sm5714_fg_read_temp(struct sm5714_fg *drv, int *temp)
{
	int raw = sm5714_fg_read_sram(drv, SM5714_FG_ADDR_SRAM_TEMPERATURE);
	int val;

	if (raw < 0)
		return raw;

	val = (((raw & 0x7fff) * 10) * 2989) >> 19;
	if (raw & 0x8000)
		val = -val;

	*temp = val;
	return 0;
}

static int sm5714_fg_get_online(int *online)
{
	union power_supply_propval val;
	struct power_supply *psy;
	int ret;

	psy = power_supply_get_by_name("sm5714_charger");
	if (!psy) {
		*online = SEC_BATTERY_CABLE_NONE;
		return 0;
	}

	ret = power_supply_get_property(psy, POWER_SUPPLY_PROP_ONLINE, &val);
	power_supply_put(psy);
	if (ret) {
		*online = SEC_BATTERY_CABLE_NONE;
		return 0;
	}

	*online = val.intval ? SEC_BATTERY_CABLE_USB : SEC_BATTERY_CABLE_NONE;
	return 0;
}

static int sm5714_fg_get_property(struct power_supply *psy,
				  enum power_supply_property psp,
				  union power_supply_propval *val)
{
	struct sm5714_fg *drv = power_supply_get_drvdata(psy);
	int error, tmp;

	switch (psp) {
	case POWER_SUPPLY_PROP_PRESENT:
		val->intval = 1;
		break;
	case POWER_SUPPLY_PROP_ONLINE:
		sm5714_fg_get_online(&tmp);
		val->intval = tmp;
		break;
	case POWER_SUPPLY_PROP_HEALTH:
		val->intval = POWER_SUPPLY_HEALTH_GOOD;
		break;
	case POWER_SUPPLY_PROP_TECHNOLOGY:
		val->intval = POWER_SUPPLY_TECHNOLOGY_LION;
		break;
	case POWER_SUPPLY_PROP_STATUS:
		error = sm5714_fg_get_status(&tmp);
		if (error)
			return error;
		val->intval = tmp;
		break;
	case POWER_SUPPLY_PROP_TEMP:
		error = sm5714_fg_read_temp(drv, &tmp);
		if (error)
			return error;
		val->intval = tmp;
		break;
	case POWER_SUPPLY_PROP_CAPACITY:
		error = sm5714_fg_read_capacity(drv, &tmp);
		if (error)
			return error;
		val->intval = tmp;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		error = sm5714_fg_read_vbat_mv(drv, &tmp);
		if (error)
			return error;
		val->intval = tmp * 1000;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_OCV:
		error = sm5714_fg_read_ocv_mv(drv, &tmp);
		if (error)
			return error;
		val->intval = tmp * 1000;
		break;
	case POWER_SUPPLY_PROP_CURRENT_NOW:
		error = sm5714_fg_read_current_ua(drv, &tmp);
		if (error)
			return error;
		val->intval = tmp;
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

static void sm5714_fg_poll_work(struct work_struct *work)
{
	struct sm5714_fg *drv = container_of(work, struct sm5714_fg, poll_work.work);
	int cap = drv->last_capacity;
	int status = drv->last_status;
	int vbat_mv = drv->last_voltage_mv;
	int temp = drv->last_temp;
	bool changed = false;

	if (sm5714_fg_read_capacity(drv, &cap) == 0 && cap != drv->last_capacity)
		changed = true;
	if (sm5714_fg_get_status(&status) == 0 && status != drv->last_status)
		changed = true;
	if (sm5714_fg_read_vbat_mv(drv, &vbat_mv) == 0 &&
	    abs(vbat_mv - drv->last_voltage_mv) >= 20)
		changed = true;
	if (sm5714_fg_read_temp(drv, &temp) == 0 &&
	    abs(temp - drv->last_temp) >= 5)
		changed = true;

	if (changed) {
		drv->last_capacity = cap;
		drv->last_status = status;
		drv->last_voltage_mv = vbat_mv;
		drv->last_temp = temp;
		power_supply_changed(drv->psy);
	}

	schedule_delayed_work(&drv->poll_work, msecs_to_jiffies(SM5714_FG_POLL_MS));
}

static const struct power_supply_desc sm5714_fg_desc = {
	.name			= "sm5714_fg",
	.type			= POWER_SUPPLY_TYPE_BATTERY,
	.properties		= sm5714_fg_props,
	.num_properties		= ARRAY_SIZE(sm5714_fg_props),
	.get_property		= sm5714_fg_get_property,
};

static int sm5714_fg_probe(struct i2c_client *i2c)
{
	struct sm5714_fg *drv;
	struct power_supply *psy;
	struct power_supply_config fg_cfg = {};

	drv = devm_kzalloc(&i2c->dev, sizeof(*drv), GFP_KERNEL);
	if (!drv)
		return -ENOMEM;

	drv->i2c = i2c;
	drv->last_capacity = -1;
	drv->last_status = -1;
	drv->last_voltage_mv = -1;
	drv->last_temp = INT_MIN;
	mutex_init(&drv->lock);
	i2c_set_clientdata(i2c, drv);

	fg_cfg.drv_data = drv;

	psy = devm_power_supply_register(&i2c->dev, &sm5714_fg_desc, &fg_cfg);
	if (IS_ERR(psy)) {
		dev_err(&i2c->dev, "failed to register power supply\n");
		return PTR_ERR(psy);
	}

	drv->psy = psy;
	INIT_DELAYED_WORK(&drv->poll_work, sm5714_fg_poll_work);
	schedule_delayed_work(&drv->poll_work, msecs_to_jiffies(1500));

	return 0;
}

static void sm5714_fg_remove(struct i2c_client *i2c)
{
	struct sm5714_fg *drv = i2c_get_clientdata(i2c);

	cancel_delayed_work_sync(&drv->poll_work);
}

static int sm5714_fg_suspend(struct device *dev)
{
	struct sm5714_fg *drv = dev_get_drvdata(dev);

	cancel_delayed_work_sync(&drv->poll_work);
	return 0;
}

static int sm5714_fg_resume(struct device *dev)
{
	struct sm5714_fg *drv = dev_get_drvdata(dev);

	schedule_delayed_work(&drv->poll_work, msecs_to_jiffies(200));
	return 0;
}

static DEFINE_SIMPLE_DEV_PM_OPS(sm5714_fg_pm_ops,
				sm5714_fg_suspend,
				sm5714_fg_resume);

static const struct i2c_device_id sm5714_i2c_ids[] = {
	{ "sm5714-fg", 0 },
	{ },
};
MODULE_DEVICE_TABLE(i2c, sm5714_i2c_ids);

static const struct of_device_id sm5714_of_match_table[] = {
	{ .compatible = "siliconmitus,sm5714-fg", },
	{ },
};
MODULE_DEVICE_TABLE(of, sm5714_of_match_table);

static struct i2c_driver sm5714_fg_driver = {
	.driver = {
		.name = "sm5714-fg",
		.of_match_table = sm5714_of_match_table,
		.pm = pm_sleep_ptr(&sm5714_fg_pm_ops),
	},
	.probe		= sm5714_fg_probe,
	.remove		= sm5714_fg_remove,
	.id_table	= sm5714_i2c_ids,
};

module_i2c_driver(sm5714_fg_driver);

MODULE_DESCRIPTION("Samsung SM5714-FG");
MODULE_AUTHOR("map220v <map220v300@gmail.com>");
MODULE_LICENSE("GPL");
