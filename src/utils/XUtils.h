//
// Created by somepineaple on 1/31/22.
//

#ifndef MC_INJECTION_XUTILS_H
#define MC_INJECTION_XUTILS_H

#include <X11/extensions/XTest.h>
#include <X11/Xlib.h>

namespace XUtils {
    struct DeviceState {
        bool *buttonStates;
        bool *keyStates;
        int *valuatorStates;

        int numKeys;
        int numButtons;
        int numValuators;
    };

    XDeviceInfo *findDeviceInfo(Display *display, const char *name, bool only_extended);
    DeviceState *getDeviceState(Display *display, unsigned long deviceID);
    void clickMouseXTest(Display *dpy, int button, long delayMS);
    void clickMouseXEvent(int button, long delayMS);
}

#endif //MC_INJECTION_XUTILS_H
