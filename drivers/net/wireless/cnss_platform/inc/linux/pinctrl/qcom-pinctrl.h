/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _COMPAT_QCOM_PINCTRL_H
#define _COMPAT_QCOM_PINCTRL_H

#include <linux/types.h>

static inline int msm_gpio_mpm_wake_set(unsigned int gpio, bool on)
{
	return 0;
}

#endif /* _COMPAT_QCOM_PINCTRL_H */
