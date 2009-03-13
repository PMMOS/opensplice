
#ifndef NW_CHANNEL_H
#define NW_CHANNEL_H

#include "os_time.h"          /* For os_time */
#include "nw_commonTypes.h"   /* For nw_name */
#include "nw_plugTypes.h"     /* For policy-kinds */
#include "kernelModule.h"     /* For v_message and v_topic */

/* 
 * All types have protected constructors
 * called by networkingBridge functions
 */


/* Abstract baseclass */

NW_CLASS(nw_channel);


/* receiveChannel */

NW_CLASS(nw_receiveChannel);

void nw_receiveChannelAddGroup(
         nw_receiveChannel channel,
         v_networkReaderEntry entry);

void nw_receiveChannelTrigger(
         nw_receiveChannel channel);

void nw_receiveChannelFree(
         nw_receiveChannel channel);


/* Reader/Write info for p2p communication */
struct nw_endpointInfo {
   c_ulong messageId;
   v_gid   sender;
   c_bool  sendTo;
   v_gid   receiver; /* Valid only if sendTo == TRUE */
};

typedef c_voidp nw_entryLookupArg;

typedef C_STRUCT(v_networkReaderEntry)* (*nw_entryLookupAction) (
    v_networkHashValue hashValue,
    const char *partitionName,
    const char *topicName,
    nw_entryLookupArg arg);
                      
/* The entry lookupaction is called at the moment that a message for an
 * unknown partition/topic has been received */
void nw_receiveChannelRead(
         nw_receiveChannel receiveChannel,
         v_message *messagePtr,
         v_networkReaderEntry *entryPtr,
         const nw_entryLookupAction entryLookupAction,
         nw_entryLookupArg entryLookupArg);
         
/* sendChannel */

NW_CLASS(nw_sendChannel);

void nw_sendChannelFree(
         nw_sendChannel channel);

/* Function returns number of bytes sent */
c_ulong nw_sendChannelWrite(
         nw_sendChannel sendChannel,
         v_networkReaderEntry entry,
         v_message message,
         nw_signedLength *maxBytes);
         
nw_bool nw_sendChannelFlush(
            nw_sendChannel sendChannel,
            nw_bool all,
            nw_signedLength *maxBytes);

void nw_sendChannelPeriodicAction(
         nw_sendChannel sendChannel,
         nw_signedLength *maxBytes);

#endif /* NW_CHANNEL_H */

