//
// Created by somepineaple on 1/30/22.
//

#include "AutoClicker.h"

#include <thread>
#include "../utils/MathHelper.h"
#include "../utils/ImGuiUtils.h"
#include <imgui.h>
#include "../utils/XUtils.h"

AutoClicker::AutoClicker() : Cheat("AutoClicker", "Clicks 4 u (so ur hand doesn't break)") {
    cps = 12;
    onlyInGame = true;

    clickTimer = new MSTimer();
    eventTimer = new MSTimer();

    nextDelay = 0;
    eventDelay = 350;
    nextEventDelay = (int)(MathHelper::randFloat(0.8, 1.2) * (float)eventDelay);
    dropChance = 0.3;
    spikeChance = 0.2;
    holdLength = 0.15;
    holdLengthRandom = 0;
    isSpiking = false;
    isDropping = false;
    showAdvanced = false;
}

void AutoClicker::run(Minecraft *mc) {
    if (XUtils::mouseDeviceID == 0 || (!mc->isInGameHasFocus() && onlyInGame))
        return;

    Display *dpy = XOpenDisplay(nullptr);
    XUtils::DeviceState mouseState = XUtils::getDeviceState(dpy, XUtils::mouseDeviceID);
    XCloseDisplay(dpy);

    if (mouseState.numButtons == 0) {
        XUtils::isDeviceShit = true;
        free(mouseState.keyStates);
        free(mouseState.buttonStates);
        free(mouseState.valuatorStates);
        return;
    } else {
        XUtils::isDeviceShit = false;
    }

    if (mouseState.buttonStates[1]) {
        if (clickTimer->hasTimePassed(nextDelay)) {
            clickTimer->reset();
            updateValues();
            // Click in new detached thread so the delay doesn't affect other modules and frame times
            std::thread(XUtils::clickMouseXEvent, 1, (int) ((float) nextDelay * holdLength * MathHelper::randFloat(1 - holdLengthRandom, 1 + holdLengthRandom))).detach();
        }
    } else {
        clickTimer->reset();
    }
}

void AutoClicker::renderSettings() {
    ImGui::SliderFloat("CPS", &cps, 4, 20);
    ImGui::Checkbox("Only in game", &onlyInGame);
    ImGui::SameLine();
    ImGuiUtils::drawHelper("If checked, this will only click when you are in game, otherwise, this will click "
                           "anytime, on any window. You could go to clickspeedtest.net and check ur clicking speed if "
                           "this is not checked");
    ImGui::Checkbox("Advanced Mode", &showAdvanced);
    if (showAdvanced) {
        ImGui::SliderInt("Event Delay", &eventDelay, 0, 10000);
        ImGui::SameLine();
        ImGuiUtils::drawHelper("How long between switching from regular to spiking to dropping in milliseconds");
        ImGui::SliderFloat("Spike Chance", &spikeChance, 0.0, 1.0);
        ImGui::SliderFloat("Drop Chance", &dropChance, 0.0, 1.0);
        ImGui::SliderFloat("Hold Length", &holdLength, 0.0, 0.99);
        ImGui::SameLine();
        ImGuiUtils::drawHelper("How long to hold the button down for in terms of the delay before the next click");
        ImGui::SliderFloat("Hold Length Random", &holdLengthRandom, 0.0, 0.5);
        ImGui::SameLine();
        ImGuiUtils::drawHelper("Add extra randomness to hold length");
    }
}

void AutoClicker::updateValues() {
    if (spikeChance + dropChance > 1) {
        spikeChance = 0.5;
        dropChance = 0.5;
    }

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
