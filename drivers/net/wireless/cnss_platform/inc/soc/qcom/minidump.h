/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _COMPAT_SOC_QCOM_MINIDUMP_H
#define _COMPAT_SOC_QCOM_MINIDUMP_H

#include <linux/types.h>

struct md_region {
	char name[32];
	u32 id;
	u64 virt_addr;
	u64 phys_addr;
	u64 size;
};

static inline int msm_minidump_add_region(const struct md_region *entry)
{
	return 0;
}

static inline int msm_minidump_remove_region(const struct md_region *entry)
{
	return 0;
}

#endif /* _COMPAT_SOC_QCOM_MINIDUMP_H */
