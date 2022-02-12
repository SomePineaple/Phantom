//
// Created by somepineaple on 2/1/22.
//

#include "AimAssist.h"

#include "../vendor/imgui/imgui.h"
#include "../utils/XUtils.h"
#include "../utils/MCUtils.h"
#include "../mapping/impl/net/minecraft/entity/player/EntityPlayer.h"
#include "../mapping/impl/net/minecraft/entity/EntityPlayerSP.h"
#include "../mapping/impl/net/minecraft/client/multiplayer/WorldClient.h"
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
            float *fullRotations = MathHelper::getRotations(thePlayer, closest);

            float currentYaw = MathHelper::wrapAngleTo180(thePlayer->getRotationYaw());
            float currentPitch = MathHelper::wrapAngleTo180(thePlayer->getRotationPitch());

            int direction = MathHelper::getDirection(currentYaw, fullRotations[0]);

            thePlayer->setRotationYaw(thePlayer->getRotationYaw() + (std::min(hSpeed / ImGui::GetIO().Framerate, std::abs(fullRotations[0] - currentYaw)) * (float)direction));

            if (fullRotations[1] > currentPitch) {
                thePlayer->setRotationPitch(thePlayer->getRotationPitch() + (vSpeed / ImGui::GetIO().Framerate));
                thePlayer->setRotationPitch(std::min(thePlayer->getRotationPitch(), fullRotations[1]));
            } else if (fullRotations[1] < currentPitch) {
                thePlayer->setRotationPitch(thePlayer->getRotationPitch() - (vSpeed / ImGui::GetIO().Framerate));
                thePlayer->setRotationPitch(std::max(thePlayer->getRotationPitch(), fullRotations[1]));
            }

            free(fullRotations);
        }
    }
}

void AimAssist::renderSettings() {
    ImGui::SliderFloat("AimAssist: range", &range, 0, 6, "%.2f");
    ImGui::SliderFloat("AimAssist: FOV", &fov, 0, 180, "%.1f");
    ImGui::SliderFloat("AimAssist: hSpeed", &hSpeed, 0, 100, "%.2f");
    ImGui::SliderFloat("AimAssist: vSpeed", &vSpeed, 0, 100, "%.2f");
    ImGui::Checkbox("AimAssist: Only while clicking", &onlyOnClick);
    ImGui::Checkbox("AimAssist: Teams Check", &teams);
    ImGui::Checkbox("AimAssist: Center", &center);
    ImGui::Checkbox("AimAssist: Target Dead", &dead);
}

bool AimAssist::isInFOV(EntityPlayer *entity, Minecraft *mc, float fov) {
    float playerYaw = MathHelper::wrapAngleTo180(mc->getPlayerContainer()->getRotationYaw()) + 180;
    float *targetRotations = MathHelper::getRotations(mc->getPlayerContainer(), entity);
    float targetYaw = targetRotations[0] + 180;
    free(targetRotations);

    float diff = std::abs(MathHelper::getAngleDiff(playerYaw, targetYaw));

    return diff < fov;
}
