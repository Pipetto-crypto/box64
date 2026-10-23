#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <dlfcn.h>

#include "wrappedlibs.h"

#include "debug.h"
#include "wrapper.h"
#include "bridge.h"
#include "librarian/library_private.h"
#include "x64emu.h"
#include "emu/x64emu_private.h"
#include "callback.h"
#include "librarian.h"
#include "box64context.h"
#include "emu/x64emu_private.h"
#include "myalign.h"

const char* libavcodec62Name = "libavcodec.so.62";

#define LIBNAME libavcodec62

//#define ADDED_FUNCTIONS()                   \

//#include "generated/wrappedlibcupstypes.h"

//#include "wrappercallback.h"

#define SUPER() \
GO(0)   \
GO(1)   \
GO(2)   \
GO(3)   \
GO(4)

/* This is not a reliable mechanism on Android to determine if a library is present */
#ifndef ANDROID
// will allow wrapped lib if and only if libavutil.so.60 && libavformat.so.62 are also available!
#define PRE_INIT \
    if (BOX64ENV(nogtk)) return -2;                                     \
    {                                                                   \
        void* h = dlopen("libavutil.so.60", RTLD_LAZY | RTLD_GLOBAL);   \
        if(!h) return -2;                                               \
        else dlclose(h);                                                \
        h = dlopen("libavformat.so.62", RTLD_LAZY | RTLD_GLOBAL);       \
        if(!h) return -2;                                               \
        else dlclose(h);                                                \
    }
#endif

#include "wrappedlib_init.h"
