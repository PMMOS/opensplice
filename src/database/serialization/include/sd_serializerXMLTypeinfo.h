#ifndef SD_SERIALIZERXMLTYPEINFO_H
#define SD_SERIALIZERXMLTYPEINFO_H

#include "sd_serializer.h"
#include "c_base.h"
#include "os_if.h"

#ifdef OSPL_BUILD_SER
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

OS_API sd_serializer sd_serializerXMLTypeinfoNew(c_base base, c_bool escapeQuote);

#undef OS_API

#endif /* SD_SERIALIZERXMLTYPEINFO_H */
