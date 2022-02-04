//
// Created by somepineaple on 1/30/22.
//

#include "AutoClicker.h"

#include <thread>
#include "../utils/MathHelper.h"
#include "../utils/ImGuiUtils.h"
#include "../vendor/imgui/imgui.h"
#include "../utils/XUtils.h"

AutoClicker::AutoClicker(Phantom *phantom) : Cheat("AutoClicker", "Does mouse clicky thingy") {
    cps = 12;
    onlyInGame = true;

    clickTimer = new MSTimer();
    eventTimer = new MSTimer();

    nextDelay = 0;
    eventDelay = 350;
    nextEventDelay = (int)(MathHelper::randFloat(0.8, 1.2) * (float)eventDelay);
    dropChance = 0.3;
    spikeChance = 0.2;
    isSpiking = false;
    isDropping = false;
}

void AutoClicker::run(Minecraft *mc) {
    if (!enabled || XUtils::mouseDeviceID == 0 || (!mc->isInGameHasFocus() && onlyInGame))
        return;

    Display *dpy = XOpenDisplay(nullptr);
    XUtils::DeviceState *mouseState = XUtils::getDeviceState(dpy, XUtils::mouseDeviceID);
    XCloseDisplay(dpy);

    if (mouseState->numButtons == 0) {
        XUtils::isDeviceShit = true;
        free(mouseState->keyStates);
        free(mouseState->buttonStates);
        free(mouseState->valuatorStates);
        return;
    } else {
        XUtils::isDeviceShit = false;
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

    free(mouseState->keyStates);
    free(mouseState->buttonStates);
    free(mouseState->valuatorStates);
}

void AutoClicker::renderSettings() {
    ImGui::SliderFloat("AutoClicker: CPS", &cps, 4, 20);
    ImGui::Checkbox("AutoClicker: Only in game", &onlyInGame);
    ImGui::SameLine();
    ImGuiUtils::drawHelper("If checked, this will only click when you are in game, otherwise, this will click anytime, on any window. You could go to clickspeedtest.net and check ur clicking speed if this is not checked");
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
