#pragma once
#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <string.h>

#ifdef SIO_DEBUG
    #ifdef _IOP
        #include <sior.h>
    #endif // _IOP
    #ifdef _EE
        #include <sio.h>
    #endif // _EE
#endif // SIO_DEBUG

#define PATH_SEPARATOR '/'
#define __FILENAME__ (strrchr(__FILE__, PATH_SEPARATOR) ? strrchr(__FILE__, PATH_SEPARATOR) + 1 : __FILE__)

#ifdef DEBUG_MODULE
    #define _MODULE_NAME DEBUG_MODULE
#elif defined(MODNAME)
    #define _MODULE_NAME MODNAME
#else
    #define _MODULE_NAME "wLE"
#endif

#ifdef _EE
    #define _CPU "EE"
#elif defined(_IOP)
    #define _CPU "IOP"
#endif

#ifdef SIO_DEBUG
	//defined only for debug versions using the EE_SIO patch
    #define debug_printf sio_printf
#endif

#ifndef debug_printf
    #define debug_printf printf
#endif

#ifdef DEBUG
    #define DPRINTF(f, args...) debug_printf("[%s@%s] %s:%u: " f "\n", _MODULE_NAME, _CPU, __FILENAME__, __LINE__, ##args)
#else
    #define DPRINTF(args...)
#endif

#endif // __DEBUG_H__
