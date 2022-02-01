//
// Created by somepineaple on 1/30/22.
//

#include "AutoClicker.h"

#include <thread>
#include "../utils/MathHelper.h"
#include "../vendor/imgui/imgui.h"
#include "../utils/XUtils.h"

AutoClicker::AutoClicker(Phantom *phantom) : Cheat("AutoClicker", "Does mouse clicky thingy") {
    cps = 12;

    mouseDeviceIndex = 0;
    mouseDeviceID = 0;
    isDeviceShit = true;

    clickTimer = new MSTimer();
    eventTimer = new MSTimer();

    eventDelay = 350;
    nextEventDelay = (int)(MathHelper::randFloat(0.8, 1.2) * (float)eventDelay);
    dropChance = 0.3;
    spikeChance = 0.2;
    isSpiking = false;
    isDropping = false;
}

void AutoClicker::run(Minecraft *mc) {
    if (!enabled || mouseDeviceID == 0)
        return;

    Display *dpy = XOpenDisplay(nullptr);
    XUtils::DeviceState *mouseState = XUtils::getDeviceState(dpy, mouseDeviceID);
    XCloseDisplay(dpy);

    if (mouseState->numButtons == 0) {
        isDeviceShit = true;
        return;
    } else {
        isDeviceShit = false;
    }

    if (mouseState->buttonStates[1]) {
        if (clickTimer->hasTimePassed(nextDelay)) {
            clickTimer->reset();
            updateValues();
            std::thread(XUtils::clickMouseXEvent, 1, nextDelay / 2).detach();
        }
    } else {
        clickTimer->reset();
    }
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

void AutoClicker::updateValues() {
    if (eventTimer->hasTimePassed(nextEventDelay)) {
        float randomFloat = MathHelper::randFloat(0, 1);
        if (randomFloat < spikeChance) {
            isSpiking = true;
            isDropping = false;
        } else if (randomFloat < spikeChance + dropChance) {
            isDropping = true;
            isSpiking = false;
        } else {
            isDropping = false;
            isSpiking = false;
        }
        eventTimer->reset();
        nextEventDelay = (int)((float)eventDelay * MathHelper::randFloat(0.8, 1.2));
    }

    float minCps;
    float maxCps;

    float middleCps = cps;
    if (isSpiking)
        middleCps *= MathHelper::randFloat(1.1, 1.2);
    else if (isDropping)
        middleCps *= MathHelper::randFloat(0.8, 0.9);

    maxCps = middleCps + 2;
    minCps = middleCps - 2;

    nextDelay = (int)(((float) 1000) / MathHelper::randFloat(minCps, maxCps));
}
