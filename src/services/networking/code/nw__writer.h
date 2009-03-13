#ifndef NW__WRITER_H
#define NW__WRITER_H

/* Public methods */
#include "nw_writer.h"
/* Used headers */
#include "nw_commonTypes.h"
#include "v_kernel.h"

/* Protected methods and types to be used by derived classes */

typedef nw_bool (*nw_writerWriteMessageFunc)(nw_writer writer,
                                             v_networkReaderEntry entry,  v_message message,
                                             c_ulong messageId, v_gid   sender,
                                             c_bool  sendTo, v_gid   receiver);

typedef void (*nw_writerFinalizeFunc)(nw_writer writer);

C_STRUCT(nw_writer) {
    /* VMT */
    nw_writerWriteMessageFunc writeMessageFunc;
    nw_writerFinalizeFunc finalizeFunc;
};

void
nw_writerInitialize(
    nw_writer writer,
    nw_writerWriteMessageFunc writeMessageFunc,
    nw_writerFinalizeFunc finalizeFunc);
    

#endif /*NW__WRITER_H*/
