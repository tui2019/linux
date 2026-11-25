/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _COMPAT_SOC_QCOM_SOCINFO_H
#define _COMPAT_SOC_QCOM_SOCINFO_H

#include <linux/types.h>

static inline u32 socinfo_get_serial_number(void)
{
	return 0;
}

#endif /* _COMPAT_SOC_QCOM_SOCINFO_H */
