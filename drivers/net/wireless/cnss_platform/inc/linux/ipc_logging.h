/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _COMPAT_IPC_LOGGING_H
#define _COMPAT_IPC_LOGGING_H

#include <linux/types.h>

static inline void *ipc_log_context_create(int max_num_pages,
					   const char *modname,
					   uint16_t user_version)
{
	return NULL;
}

static inline int ipc_log_context_destroy(void *ctxt)
{
	return 0;
}

#define ipc_log_string(ctxt, fmt, ...) do { } while (0)

#endif /* _COMPAT_IPC_LOGGING_H */
