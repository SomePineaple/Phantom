//
// Created by somepineaple on 2/1/22.
//

#include "AimAssist.h"

#include "../vendor/imgui/imgui.h"
#include "../utils/XUtils.h"
#include "../mapping/impl/EntityPlayer.h"
#include "../mapping/impl/EntityPlayerSP.h"
#include "../mapping/impl/WorldClient.h"
#include "../utils/MathHelper.h"

AimAssist::AimAssist(Phantom *phantom) : Cheat("AimAssist", "Aims for u, but smoooothly.") {
    this->phantom = phantom;

    range = 3.5;
    fov = 90;
    hSpeed = 10;
    vSpeed = 0;
    onlyOnClick = true;
    center = true;
    dead = false;
}

void AimAssist::run(Minecraft *mc) {
    if (!enabled || XUtils::mouseDeviceID == 0 || !mc->isInGameHasFocus())
        return;

    Display *dpy = XOpenDisplay(nullptr);
    XUtils::DeviceState *mouseState = XUtils::getDeviceState(dpy, XUtils::mouseDeviceID);
    XCloseDisplay(dpy);

    if (mouseState->numButtons == 0) {
        XUtils::isDeviceShit = true;
        return;
    } else {
        XUtils::isDeviceShit = false;
    }

    if (!onlyOnClick || mouseState->buttonStates[1]) {
        float closestDistance = range;

        EntityPlayerSP *thePlayer = mc->getPlayerContainer();

        EntityPlayer *closest = nullptr;
        JavaList *players = mc->getWorldContainer()->getPlayers();

        for (int i = 0; i < players->size(); i++) {
            auto *player = new EntityPlayer(phantom, players->get(i));
            if (player->getId() != mc->getPlayerContainer()->getId()) {
                auto newDist = (float) MathHelper::distance(player->getPosX(), player->getPosY(), player->getPosZ(), thePlayer->getPosX(), thePlayer->getPosY(), thePlayer->getPosZ());
                if (newDist < closestDistance) {
                    closestDistance = newDist;
                    closest = player;
                }
            }
        }

        if (closest != nullptr) {

        }
    }
}

void AimAssist::renderSettings() {
    ImGui::SliderFloat("AimAssist: range", &range, 0, 6, "%.2f");
    ImGui::SliderFloat("AimAssist: FOV", &fov, 0, 180, "%.1f");
    ImGui::SliderFloat("AimAssist: hSpeed", &hSpeed, 0, 10, "%.2f");
    ImGui::SliderFloat("AimAssist: vSpeed", &vSpeed, 0, 10, "%.2f");
    ImGui::Checkbox("AimAssist: Only while clicking", &onlyOnClick);
    ImGui::Checkbox("AimAssist: Center", &center);
    ImGui::Checkbox("AimAssist: Target Dead", &dead);
}
