#ifndef IN__PLUGKERNEL_H_
#define IN__PLUGKERNEL_H_

#include "in__object.h"
#include "u_service.h"
#include "u_networkReader.h"

#if defined (__cplusplus)
extern "C" {
#endif


#define in_plugKernel(p) ((in_plugKernel)(p))

#define in_plugKernelFree(p) in_objectFree(in_object(p))

#define in_plugKernelKeep(p) in_plugKernel(in_objectKeep(in_object(p)))

#define in_plugKernelIsValid(p) \
    in_objectIsValidWithKind(in_object(p), IN_OBJECT_KIND_PLUG_KERNEL)

in_plugKernel
in_plugKernelNew(
    u_service service);

u_service
in_plugKernelGetService(
    in_plugKernel _this);

u_networkReader
in_plugKernelGetNetworkReader(
    in_plugKernel _this);

#if defined (__cplusplus)
}
#endif

#endif /* IN__PLUGKERNEL_H_ */
