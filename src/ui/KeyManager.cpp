//
// Created by somepineaple on 4/18/22.
//

#include "KeyManager.h"

#include <imgui.h>
#include <malloc.h>

void KeyManager::updateKeys(Phantom *phantom) {
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

    if (previousState.keyStates == nullptr || previousState.numKeys != currentState.numKeys)
        previousState.keyStates = (bool *) malloc(currentState.numKeys * sizeof(bool));

    previousState.numKeys = currentState.numKeys;
    memcpy(previousState.keyStates, currentState.keyStates, currentState.numKeys * sizeof(bool));
}

void callUpdateKeys(KeyManager *manager, Phantom *phantom) {
    manager->updateKeys(phantom);
}
