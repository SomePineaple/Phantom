//
// Created by somepineaple on 1/30/22.
//

#include "AutoClicker.h"

#include "../utils/MathHelper.h"
#include "../utils/MiscUtils.h"
#include "../vendor/imgui/imgui.h"
#include "../utils/XUtils.h"

AutoClicker::AutoClicker(Phantom *phantom) : Cheat("AutoClicker", "Does mouse clicky thingy") {
    cps = 12;

    lastClick = MiscUtils::currentTimeMS();
    leftHold = MiscUtils::currentTimeMS();

    mouseDeviceIndex = 0;
    mouseDeviceID = 0;
    isDeviceShit = true;
}

void AutoClicker::run(Minecraft *mc) {
    if (!enabled || mouseDeviceID == 0)
        return;

    double speedLeft1 = 1.0 / MathHelper::randDouble(cps - 2.2, cps + 2);
    double leftHoldLength = speedLeft1 / MathHelper::randDouble(cps - 2.2, cps + 2);

    Display *dpy = XOpenDisplay(nullptr);
    XUtils::DeviceState *mouseState = XUtils::getDeviceState(dpy, mouseDeviceID);

    if (mouseState->numButtons == 0) {
        isDeviceShit = true;
        return;
    } else {
        isDeviceShit = false;
    }

    if (mouseState->buttonStates[0]) {
        double speedLeft = 1.0 / MathHelper::randDouble(cps - 2.2, cps + 2);
        if ((double)(MiscUtils::currentTimeMS() - lastClick) > speedLeft * 1000) {
            lastClick = MiscUtils::currentTimeMS();
            if (leftHold < lastClick)
                leftHold = lastClick;
            XTestFakeButtonEvent(dpy, 1, true, CurrentTime);
            XFlush(dpy);
        } else if ((double)(MiscUtils::currentTimeMS() - leftHold) > leftHoldLength * 1000) {
            XTestFakeButtonEvent(dpy, 1, false, CurrentTime);
            XFlush(dpy);
        }
    }

    XCloseDisplay(dpy);
}

void AutoClicker::renderSettings() {
    ImGui::SliderFloat("AutoClicker: CPS", &cps, 4, 20);
    Display *dpy = XOpenDisplay(nullptr);
    XDeviceInfo *devices;
    int numDevices;
    devices = XListInputDevices(dpy, &numDevices);

    if (isDeviceShit)
        ImGui::Text("Please select a valid mouse device");
    else
        ImGui::Text("Valid Mouse Selected");

    std::string comboItems;
    for (int i = 0; i < numDevices; i++) {
        comboItems.append(devices[i].name);
        comboItems.push_back('\0');
    }

    if (ImGui::Combo("AutoClicker: Select your mouse", &mouseDeviceIndex, comboItems.c_str()))
        mouseDeviceID = devices[mouseDeviceIndex].id;

    XFreeDeviceList(devices);
    XCloseDisplay(dpy);
}
