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

        std::cout << "Getting player container" << std::endl;
        EntityPlayerSP *thePlayer = mc->getPlayerContainer();

        EntityPlayer *closest = nullptr;
        std::cout << "Getting players list" << std::endl;
        JavaList *players = mc->getWorldContainer()->getPlayers();
        if (players == nullptr)
            return;

        std::cout << "Looping through players, number of players is: " << players->size() << std::endl;
        for (int i = 0; i < players->size(); i++) {
            std::cout << "Getting player #" << i << std::endl;
            auto *player = new EntityPlayer(phantom, players->get(i));
            std::cout << "Got player #" << i << " player id is " << player->getId() << std::endl;
            if (player->getId() != mc->getPlayerContainer()->getId() && isInFOV(player, mc, fov)) {
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
    ImGui::SliderFloat("AimAssist: hSpeed", &hSpeed, 0, 10, "%.2f");
    ImGui::SliderFloat("AimAssist: vSpeed", &vSpeed, 0, 10, "%.2f");
    ImGui::Checkbox("AimAssist: Only while clicking", &onlyOnClick);
    ImGui::Checkbox("AimAssist: Center", &center);
    ImGui::Checkbox("AimAssist: Target Dead", &dead);
}

bool AimAssist::isInFOV(EntityPlayer *entity, Minecraft *mc, float fov) {
    std::cout << "Checking if player with id " << entity->getId() << " is in the FOV" << std::endl;
    float playerYaw = MathHelper::wrapAngleTo180(mc->getPlayerContainer()->getRotationYaw()) + 180;
    float *targetRotations = MathHelper::getRotations(mc->getPlayerContainer(), entity);
    float targetYaw = targetRotations[0];
    free(targetRotations);

    float diff = std::abs(MathHelper::getAngleDiff(playerYaw, targetYaw));

    return diff < fov;
}
