
#ifndef V__SUBSCRIBER_H
#define V__SUBSCRIBER_H

#if defined (__cplusplus)
extern "C" {
#endif

#include "v_subscriber.h"
#include "v_subscriberQos.h"
#include "v_reader.h"
#include "v_entity.h"
#include "v_event.h"

v_result
v_subscriberSetQos(
    v_subscriber _this,
    v_subscriberQos qos);

void
v_subscriberNotify(
    v_subscriber _this,
    v_event event);

v_reader
v_subscriberRemoveShare(
    v_subscriber _this,
    v_reader reader);

v_reader
v_subscriberAddShareUnsafe(
    v_subscriber _this,
    v_reader r);

v_reader
v_subscriberRemoveShareUnsafe(
    v_subscriber _this,
    v_reader r);

void
v_subscriberLockShares(
    v_subscriber _this);

void
v_subscriberUnlockShares(
    v_subscriber _this);

#if defined (__cplusplus)
}
#endif

#endif /* V__SUBSCRIBER_H */
