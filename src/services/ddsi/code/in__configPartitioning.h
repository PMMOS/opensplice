/* Prevent failure due to multiple inclusion of this file. */
#ifndef IN_CONFIG_PARTITIONING_H
#define IN_CONFIG_PARTITIONING_H

/* OS abstraction includes. */
#include "os_defs.h"
#include "os_classbase.h"
#include "os_stdlib.h"

/* Collection includes */
#include "Coll_List.h"

/* DDSi includes */
#include "in__configNetworkPartition.h"
#include "in__configPartitionMapping.h"
#include "in__configTypes.h"

/**
 * Allow usage of this C code from C++ code.
 */
#if defined (__cplusplus)
extern "C" {
#endif



/**
 * Macro that allows the implementation of type checking when casting an
 * object. The signature of the 'casting macro' must look like this:
 */
#define in_configPartitioning(_this) ((in_configPartitioning)_this)

in_configPartitioning
in_configPartitioningNew(
    );

os_char*
in_configPartitioningGetGlobalPartitionAddress(
    in_configPartitioning _this);

/* List contains 'in_configNetworkPartition' objects */
Coll_List*
in_configPartitioningGetNetworkPartitions(
    in_configPartitioning _this);

Coll_List*
in_configPartitioningGetPartitionsMappings(
    in_configPartitioning _this);

os_char*
in_configPartitioningGetPathName(
    in_configPartitioning _this);

void
in_configPartitioningSetGlobalPartitionAddress(
    in_configPartitioning _this,
    os_char* address);

void
in_configPartitioningAddNetworkPartition(
    in_configPartitioning _this,
    in_configNetworkPartition networkPartition);

void
in_configPartitioningAddPartitionMapping(
    in_configPartitioning _this,
    in_configPartitionMapping partitionMapping);

/* Close the brace that allows the usage of this code in C++. */
#if defined (__cplusplus)
}
#endif

#endif /* IN_CONFIG_PARTITIONING_H */
