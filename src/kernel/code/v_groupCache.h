

#ifndef V_GROUPCACHE_H
#define V_GROUPCACHE_H

#include <v_kernel.h>
#include <v_cache.h>

#define v_groupCache(o) (C_CAST((o),v_groupCache))

v_groupCache
v_groupCacheNew (
    v_kernel kernel, 
    v_cacheKind kind);

void
v_groupCacheInsert (
    v_groupCache _this, 
    v_groupCacheItem item);

#define v_groupCacheWalk(_this,_action,_arg) \
        v_cacheWalk(v_cache(_this),_action,_arg)

void
v_groupCacheDeinit (
    v_groupCache _this);

/* inner class: v_groupCacheItem */

#define v_groupCacheItem(o) (C_CAST((o),v_groupCacheItem))

v_groupCacheItem
v_groupCacheItemNew (
    v_groupInstance groupInstance, 
    v_instance instance);

v_instance
v_groupCacheItemObject (
    v_groupCacheItem _this);

void
v_groupCacheItemRemove (
    v_groupCacheItem _this, 
    v_cacheKind kind);

#endif

