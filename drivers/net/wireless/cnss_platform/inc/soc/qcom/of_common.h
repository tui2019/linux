/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _COMPAT_SOC_QCOM_OF_COMMON_H
#define _COMPAT_SOC_QCOM_OF_COMMON_H

#include <linux/errno.h>

static inline int of_fdt_get_ddrtype(void)
{
	return -ENOENT;
}

#endif /* _COMPAT_SOC_QCOM_OF_COMMON_H */
