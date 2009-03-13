
/****************************************************************
 * Initialization / Deinitialization                            *
 ****************************************************************/

/** \file os/linux/code/os_init.c
 *  \brief Initialization / Deinitialization
 */

#include <code/os__process.h>
#include <code/os__thread.h>
#include <code/os__sharedmem.h>

/** \brief OS layer initialization
 *
 * \b os_osInit calls:
 * - \b os_sharedMemoryInit
 * - \b os_threadInit
 */
void
os_osInit (
    void)
{
    os_processModuleInit();
    os_threadModuleInit();
    os_sharedMemoryInit();
    return;
}

/** \brief OS layer deinitialization
 *
 * \b os_osExit calls:
 * - \b os_sharedMemoryExit
 * - \b os_threadExit
 */
void
os_osExit (
    void)
{
    os_sharedMemoryExit();
    os_threadModuleExit();
    os_processModuleExit();
    return;
}

#include <../common/code/os_service.c>
