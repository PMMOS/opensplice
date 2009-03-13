#ifndef U_GROUPQUEUE_H
#define U_GROUPQUEUE_H

#include "u_types.h"
#include "u_reader.h"
#include "v_readerQos.h"

#if defined (__cplusplus)
extern "C" {
#endif
#include "os_if.h"

#ifdef OSPL_BUILD_USER
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

#define u_groupQueue(o)   ((u_groupQueue)(o))

OS_API u_groupQueue  u_groupQueueNew           (u_subscriber s, const c_char *name,
                                                c_ulong queueSize, v_readerQos qos);
                                             
OS_API u_result            u_groupQueueInit    (u_groupQueue q);

OS_API u_result            u_groupQueueFree    (u_groupQueue q);

OS_API u_result            u_groupQueueDeinit  (u_groupQueue q);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif /*U_GROUPQUEUE_H*/
