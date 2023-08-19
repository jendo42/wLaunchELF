#pragma once
#ifndef __PS2HOST_DEBUG_H__
#define __PS2HOST_DEBUG_H__

#define DEBUG_MODULE "ps2host"
#include "../debug.h"

#ifdef DEBUG
#define dbgprintf(args...) DPRINTF(args)
#else
#define dbgprintf(args...) \
    do {                   \
    } while (0)
#endif

#endif // __PS2HOST_DEBUG_H__
