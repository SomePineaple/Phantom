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

    mouse = new Mouse(phantom);
    lastClick = MiscUtils::currentTimeMS();
    leftHold = MiscUtils::currentTimeMS();

    mouseDeviceIndex = 0;
    mouseDeviceID = 0;
}

void AutoClicker::run(Minecraft *mc) {
    if (!enabled)
        return;

    double speedLeft1 = 1.0 / MathHelper::randDouble(cps - 2.2, cps + 2);
    double leftHoldLength = speedLeft1 / MathHelper::randDouble(cps - 2.2, cps + 2);

    if (mouse->isButtonDown(0)) {
        KeyBinding *keyBindAttack = mc->getGameSettingsContainer()->getKeyBindAttackContainer();
        int keyCode = keyBindAttack->getKeyCode();

        double speedLeft = 1.0 / MathHelper::randDouble(cps - 2.2, cps + 2);
        if ((double)(MiscUtils::currentTimeMS() - lastClick) > speedLeft * 1000) {
            lastClick = MiscUtils::currentTimeMS();
            if (leftHold < lastClick)
                leftHold = lastClick;
            keyBindAttack->setKeyBindState(keyCode, true);
            keyBindAttack->onTick(keyCode);
        } else if ((double)(MiscUtils::currentTimeMS() - leftHold) > leftHoldLength * 1000) {
            keyBindAttack->setKeyBindState(keyCode, false);
        }
    }
}

void AutoClicker::renderSettings() {
    ImGui::SliderFloat("AutoClicker: CPS", &cps, 4, 20);
    Display *dpy = XOpenDisplay(nullptr);
    XDeviceInfo *devices;
    int numDevices;
    devices = XListInputDevices(dpy, &numDevices);

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
