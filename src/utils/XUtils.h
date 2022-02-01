//
// Created by somepineaple on 1/31/22.
//

#ifndef MC_INJECTION_XUTILS_H
#define MC_INJECTION_XUTILS_H

#include <X11/extensions/XTest.h>
#include "X11/Xlib.h"

namespace XUtils {
    XDeviceInfo* findDeviceInfo(Display *display, char *name, bool only_extended);
}

#endif //MC_INJECTION_XUTILS_H
