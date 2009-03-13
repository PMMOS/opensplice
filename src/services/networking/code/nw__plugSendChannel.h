
#ifndef NW__PLUGSENDCHANNEL_H_
#define NW__PLUGSENDCHANNEL_H_

#include "nw_plugSendChannel.h"
#include "nw_plugChannel.h"
#include "nw_plugPartitions.h"

/* Constructor, to be called by plugNetwork onwly */

nw_plugChannel nw_plugSendChannelNew(
                   nw_seqNr seqNr,
                   nw_networkId nodeId,
                   nw_plugPartitions plugPartitions,
                   nw_userData *userDataPtr,
                   const char *pathName,
                   nw_onFatalCallBack onFatal,
                   c_voidp onFatalUsrData);                   

void nw_plugSendChannelFree(
                   nw_plugChannel channel);

#endif /*NW__PLUGSENDCHANNEL_H_*/
