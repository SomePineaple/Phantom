//
// Created by somepineaple on 1/31/22.
//

#include "XUtils.h"

#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cstdio>

XUtils::DeviceState XUtils::getButtonList(Display *display, unsigned long deviceID) {
    DeviceState state{};

    XDevice *device = XOpenDevice(display, deviceID);
    XDeviceState *xState = XQueryDeviceState(display, device);

    XValuatorState *valState;
    XButtonState *buttonState;
    XKeyState *keyState;

    if (xState) {
        XInputClass *cls = xState->data;

        for (int i = 0; i < xState->num_classes; i++) {
            switch(cls->c_class) {
            case ValuatorClass:
                valState = (XValuatorState *) cls;
                state.numValuators = valState->num_valuators;
                for (int i2 = 0; i2 < valState->num_valuators; i2++)
                    state.valuatorStates[i2] = valState->valuators[i2];
                break;
            case ButtonClass:
                buttonState = (XButtonState *) cls;
                state.numButtons = buttonState->num_buttons;
                for (int i2 = 0; i2 < buttonState->num_buttons; i2++)
                    state.buttonStates[i2] = (buttonState->buttons[i2 / 8] & (1 << (i2 % 8))) != 0;
                break;
            case KeyClass:
                keyState = (XKeyState *) cls;
                state.numKeys = keyState->num_keys;
                for (int i2 = 0; i2 < keyState->num_keys; i2++)
                    state.keyStates[i2] = (keyState->keys[i2 / 8] & (1 << (i2 % 8))) != 0;
                break;
            }
            cls = (XInputClass *) ((char *) cls + cls->length);
        }
        XFreeDeviceState(xState);
    }

    return state;
}

XDeviceInfo* XUtils::findDeviceInfo(Display *display, const char *name, bool only_extended) {
    XDeviceInfo	*devices;
    XDeviceInfo *found = nullptr;
    int		loop;
    int		num_devices;
    int		len = (int) strlen(name);
    bool	is_id = true;
    XID		id = (XID)-1;

    for(loop=0; loop<len; loop++) {
        if (!isdigit(name[loop])) {
            is_id = false;
            break;
        }
    }

    if (is_id) {
        id = atoi(name);
    }

    devices = XListInputDevices(display, &num_devices);

    for(loop=0; loop<num_devices; loop++) {
        if ((!only_extended || (devices[loop].use >= IsXExtensionDevice)) &&
            ((!is_id && strcmp(devices[loop].name, name) == 0) ||
             (is_id && devices[loop].id == id))) {
            if (found) {
                fprintf(stderr,
                        "Warning: There are multiple devices named '%s'.\n"
                        "To ensure the correct one is selected, please use "
                        "the device ID instead.\n\n", name);
                return nullptr;
            } else {
                found = &devices[loop];
            }
        }
    }
    return found;
}
