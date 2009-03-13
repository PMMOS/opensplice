#ifndef V_NETWORKQUEUE_H
#define V_NETWORKQUEUE_H

#include "v_kernel.h"
#include "v_networkReader.h"
#include "os_if.h"

#ifdef OSPL_BUILD_KERNEL
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

OS_API c_type
v_networkQueue_t (
    c_base base);

OS_API v_networkQueue
v_networkQueueNew(
    c_base base,
    c_ulong queueSize,
    c_ulong priority,
    c_bool reliable,
    c_bool P2P,
    c_time resolution);

OS_API c_bool
v_networkQueueWrite(
    v_networkQueue _this,
    v_message message,
    v_networkReaderEntry entry,
    c_long sequenceNumber,
    v_gid sender,
    c_bool sendTo, /* for p2p writing */
    v_gid receiver);

OS_API c_bool
v_networkQueueTakeFirst(
    v_networkQueue _this,
    v_message *message,
    v_networkReaderEntry *entry,
    c_ulong *sequenceNumber,
    v_gid *sender,
    c_bool *sendTo, /* for p2p writing */
    v_gid *receiver,
    c_time *sendBefore,
    c_ulong *priority,
    c_bool *more);

OS_API v_networkReaderWaitResult
v_networkQueueWait(
    v_networkQueue _this);

OS_API void
v_networkQueueTrigger(
    v_networkQueue _this);
                    
#undef OS_API

#endif /* V_NETWORKQUEUE_H */
