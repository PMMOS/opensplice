#ifndef U_READERQOS_H
#define U_READERQOS_H

#if defined (__cplusplus)
extern "C" {
#endif

#include "u_types.h"
#include "v_kernel.h"
#include "os_if.h"

#ifdef OSPL_BUILD_USER
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

OS_API v_readerQos u_readerQosNew    (v_readerQos tmpl);
OS_API u_result    u_readerQosInit   (v_readerQos q);
OS_API void        u_readerQosDeinit (v_readerQos q);
OS_API void        u_readerQosFree   (v_readerQos q);

#undef OS_API 

#if defined (__cplusplus)
}
#endif

#endif /* U_READERQOS_H */
