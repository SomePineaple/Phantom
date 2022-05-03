//
// Created by somepineaple on 2/1/22.
//

#include "AimAssist.h"

#include <net/minecraft/entity/EntityPlayerSP.h>
#include <net/minecraft/client/multiplayer/WorldClient.h>
#include <imgui.h>
#include "../utils/XUtils.h"
#include "../utils/MCUtils.h"
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
    teams = false;
}

void AimAssist::run(Minecraft *mc) {
    if (XUtils::mouseDeviceID == 0 || !mc->isInGameHasFocus())
        return;

    Display *dpy = XOpenDisplay(nullptr);
    XUtils::DeviceState mouseState = XUtils::getDeviceState(dpy, XUtils::mouseDeviceID);
    XCloseDisplay(dpy);

    if (mouseState.numButtons == 0) {
        XUtils::isDeviceShit = true;
        return;
    } else {
        XUtils::isDeviceShit = false;
    }

    if (!onlyOnClick || mouseState.buttonStates[1]) {
        float closestDistance = range;

        EntityPlayerSP *thePlayer = mc->getPlayerContainer();

        EntityPlayer *closest = nullptr;
        JavaList *players = mc->getWorldContainer()->getPlayers();
        if (players == nullptr)
            return;

        for (int i = 0; i < players->size(); i++) {
            auto *player = new EntityPlayer(phantom, players->get(i));
            if ((player->getId() != mc->getPlayerContainer()->getId()) && isInFOV(player, mc, fov) && !(MCUtils::sameTeam(mc, player) && teams)) {
                auto newDist = (float) MathHelper::distance(player->getPosX(), player->getPosY(), player->getPosZ(), thePlayer->getPosX(), thePlayer->getPosY(), thePlayer->getPosZ());
                if (newDist < closestDistance) {
                    closestDistance = newDist;
                    closest = player;
                }
            }
        }

        if (closest != nullptr) {
            MathHelper::Vec2 fullRotations = MathHelper::getRotations(thePlayer, closest);

            float currentYaw = MathHelper::wrapAngleTo180(thePlayer->getRotationYaw());
            float currentPitch = MathHelper::wrapAngleTo180(thePlayer->getRotationPitch());

            int direction = MathHelper::getDirection(currentYaw, fullRotations.x);

            thePlayer->setRotationYaw(thePlayer->getRotationYaw() + (std::min(hSpeed / ImGui::GetIO().Framerate, (float)std::abs(fullRotations.x - currentYaw)) * (float)direction));

            if (fullRotations.y > currentPitch) {
                thePlayer->setRotationPitch(thePlayer->getRotationPitch() + (vSpeed / ImGui::GetIO().Framerate));
                thePlayer->setRotationPitch(std::min(thePlayer->getRotationPitch(), (float)fullRotations.y));
            } else if (fullRotations.y < currentPitch) {
                thePlayer->setRotationPitch(thePlayer->getRotationPitch() - (vSpeed / ImGui::GetIO().Framerate));
                thePlayer->setRotationPitch(std::max(thePlayer->getRotationPitch(), (float)fullRotations.y));
            }

        }
    }
}

void AimAssist::renderSettings() {
    ImGui::SliderFloat("range", &range, 0, 6, "%.2f");
    ImGui::SliderFloat("FOV", &fov, 0, 180, "%.1f");
    ImGui::SliderFloat("hSpeed", &hSpeed, 0, 100, "%.2f");
    ImGui::SliderFloat("vSpeed", &vSpeed, 0, 100, "%.2f");
    ImGui::Checkbox("Only while clicking", &onlyOnClick);
    ImGui::Checkbox("Teams Check", &teams);
    ImGui::Checkbox("Center", &center);
    ImGui::Checkbox("Target Dead", &dead);
}

bool AimAssist::isInFOV(EntityPlayer *entity, Minecraft *mc, float fov) {
    float playerYaw = MathHelper::wrapAngleTo180(mc->getPlayerContainer()->getRotationYaw()) + 180;
    MathHelper::Vec2 targetRotations = MathHelper::getRotations(mc->getPlayerContainer(), entity);
    float targetYaw = targetRotations.x + 180;

    float diff = std::abs(MathHelper::getAngleDiff(playerYaw, targetYaw));

    return diff < fov;
}
