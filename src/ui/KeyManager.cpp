//
// Created by somepineaple on 4/18/22.
//

#include "KeyManager.h"

void KeyManager::updateKeys(Phantom *phantom) {
    if (XUtils::keyboardDeviceID == 0)
        return;

    Display *dpy = XOpenDisplay(nullptr);
    XUtils::DeviceState currentState = XUtils::getDeviceState(dpy, XUtils::keyboardDeviceID);
    XCloseDisplay(dpy);

    // Basic check to see if we didn't just change input devices
    if (previousState.numKeys == currentState.numKeys) {
        for (int i = 0; i < currentState.numKeys; i++) {
            if (previousState.keyStates[i] != currentState.keyStates[i]) {
                if (currentState.keyStates[i]) { // Key pressed
                    phantom->onKey(i);
                }
            }
        }
    }

    previousState = currentState;
}
