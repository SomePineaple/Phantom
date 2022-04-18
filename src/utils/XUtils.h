//
// Created by somepineaple on 1/31/22.
//

#ifndef PHANTOM_XUTILS_H
#define PHANTOM_XUTILS_H

#include <X11/extensions/XTest.h>
#include <X11/Xlib.h>

namespace XUtils {
    class DeviceState {
    public:
        DeviceState();
        ~DeviceState();

        bool *buttonStates;
        bool *keyStates;
        int *valuatorStates;

        int numKeys;
        int numButtons;
        int numValuators;
    };

    extern int mouseDeviceIndex;
    extern int keyboardDeviceIndex;
    extern unsigned long mouseDeviceID;
    extern unsigned long keyboardDeviceID;
    extern bool isDeviceShit;

    void renderMouseSelector();
    void renderKeyboardSelector();

    XDeviceInfo *findDeviceInfo(Display *display, const char *name, bool only_extended);
    DeviceState getDeviceState(Display *display, unsigned long deviceID);
    void clickMouseXEvent(int button, long delayMS);
}

#endif //PHANTOM_XUTILS_H
