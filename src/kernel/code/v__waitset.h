
#ifndef V__WAITSET_H
#define V__WAITSET_H

#include "v_waitset.h"

/**
 * Releases all resources claimed by the referenced waitset object.
 *
 * \param _this  a reference to the waitset object.
 */
void
v_waitsetDeinit(
    v_waitset _this);

/**
 * Notifies the waitset on a state change of one of the conditions.
 * Every event the waitset receives is stored in a list. The events
 * are grouped on the origin of the event.
 *
 * \param _this    a reference to the waitset object.
 * \param e        a reference to the event describing the reason of the
 *                 notification.
 * \param userData data that has to be forwarded with the given event.
 */
void
v_waitsetNotify(
    v_waitset _this,
    v_event e,
    c_voidp userData);

#endif
