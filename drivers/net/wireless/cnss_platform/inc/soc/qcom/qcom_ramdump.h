/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _COMPAT_SOC_QCOM_RAMDUMP_H
#define _COMPAT_SOC_QCOM_RAMDUMP_H

#include <linux/device.h>
#include <linux/list.h>
#include <linux/types.h>

struct qcom_dump_segment {
	struct list_head node;
	dma_addr_t da;
	void *va;
	size_t size;
};

static inline bool dump_enabled(void)
{
	return false;
}

static inline int qcom_dump(struct list_head *head, struct device *dev)
{
	return 0;
}

static inline int qcom_elf_dump(struct list_head *head, struct device *dev,
				u8 class)
{
	return 0;
}

#endif /* _COMPAT_SOC_QCOM_RAMDUMP_H */
