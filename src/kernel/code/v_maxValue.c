 
#include "v_maxValue.h"
#include "v_timedValue.h"

void
v_maxValueInit(
    v_maxValue *_this)
{
    assert(_this != NULL);
    v_maxValueReset(_this);
}

void
v_maxValueReset(
    v_maxValue *_this)
{
    assert(_this != NULL);
    v_timedValueReset(_this);
}

c_time
v_maxValueGetTime(
    v_maxValue *_this)
{
    assert(_this != NULL);
    return v_timedValueGetTime(_this);
}

c_ulong
v_maxValueGetValue(
    v_maxValue *_this)
{
    assert(_this != NULL);
    return v_timedValueGetValue(_this);
}

void
v_maxValueSetValue(
    v_maxValue *_this, 
    c_ulong value)
{
    if (value > v_timedValueGetValue(_this)) {
        v_timedValueSetValue(_this,value);
    }
}

