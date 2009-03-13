#ifndef U_TOPICQOS_H
#define U_TOPICQOS_H

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

OS_API v_topicQos u_topicQosNew    (v_topicQos tmpl);
OS_API u_result   u_topicQosInit   (v_topicQos q);
OS_API void       u_topicQosDeinit (v_topicQos q);
OS_API void       u_topicQosFree   (v_topicQos q);

#undef OS_API 

#if defined (__cplusplus)
}
#endif

#endif /* U_TOPICQOS_H */
