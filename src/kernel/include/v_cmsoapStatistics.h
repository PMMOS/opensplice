#ifndef V_CMSOAPSTATISTICS_H
#define V_CMSOAPSTATISTICS_H

/** \file kernel/include/v_cmsoapStatistics.h
 *  \brief This file defines the interface
 *
 */

#include "v_kernel.h"
#include "os_if.h"

#ifdef OSPL_BUILD_KERNEL
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

/**
 * \brief The <code>v_cmsoapStatistics</code> cast method.
 *
 * This method casts an object to a <code>v_cmsoapStatistics</code> object.
 * Before the cast is performed, if compiled with the NDEBUG flag not set,
 * the type of the object is checked to be <code>v_cmsoapStatistics</code> or
 * one of its subclasses.
 */
#define v_cmsoapStatistics(_this) (C_CAST(_this,v_cmsoapStatistics))

OS_API v_cmsoapStatistics
v_cmsoapStatisticsNew(
    v_kernel k);

OS_API void
v_cmsoapStatisticsInit(
    v_cmsoapStatistics _this);

OS_API void
v_cmsoapStatisticsDeinit(
    v_cmsoapStatistics _this);

OS_API void
v_cmsoapStatisticsFree(
    v_cmsoapStatistics _this);

OS_API c_bool
v_cmsoapStatisticsReset(
    v_cmsoapStatistics _this,
    const c_char *fieldName);

#undef OS_API

#endif
