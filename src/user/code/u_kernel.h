
#ifndef U_KERNEL_H
#define U_KERNEL_H

#if defined (__cplusplus)
extern "C" {
#endif

#include "u_types.h"
#include "u_entity.h"

#define  u_kernel(p)     ((u_kernel)(p))
 
u_kernel u_kernelNew     (const c_char *uri);
u_kernel u_kernelOpen    (const c_char *uri, c_long timeout); /* timeout in seconds */

v_kernel u_kernelSource  (u_kernel k);

u_result u_kernelClose   (u_kernel k);
u_result u_kernelFree    (u_kernel k);

c_voidp  u_kernelGetCopy (u_kernel k, u_entityCopy copy, void* copyArg);
const c_char *u_kernelUri(u_kernel kernel);

#if defined (__cplusplus)
}
#endif

#endif
