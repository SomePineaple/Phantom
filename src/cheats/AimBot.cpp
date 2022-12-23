//
// Created by somepineaple on 1/30/22.
//

#include "AimBot.h"

#include <net/minecraft/client/multiplayer/WorldClient.h>
#include <net/minecraft/entity/EntityPlayerSP.h>
#include "../utils/XUtils.h"
#include "../utils/MathHelper.h"
#include <imgui.h>

AimBot::AimBot(Phantom *phantom) : Cheat("AimBot","Automatically puts cursor over the nearest entity. "
                                                   "Please note: there is no antibot, and also this is not aim assist. "
                                                   "This will probably insta-ban on most servers with a semi-decent "
                                                   "anticheat.") {
    this->phantom = phantom;

    range = 3.5;
    onlyOnClick = false;
}

void AimBot::run(Minecraft *mc) {
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

    EntityPlayerSP player = mc->getPlayerContainer();
    WorldClient world = mc->getWorldContainer();

    float closestDist = range;

    // Get all the entities, calculate the closest one
    JavaList entities = world.getEntities();
    Entity closest(phantom, nullptr);
    for (int i = 0; i < entities.size(); i++) {
        Entity entity(phantom, entities.get(i));
        if (entity.getId() != player.getId()) {
            auto newDist = (float)MathHelper::distance(entity.getPosX(), entity.getPosY(), entity.getPosZ(), player.getPosX(), player.getPosY(), player.getPosZ());
            if (newDist < closestDist) {
                closestDist = newDist;
                closest = entity;
            }
        }
    }

    // If there is an entity in range, look at it
    if(!onlyOnClick || mouseState.buttonStates[1])
        if (closest.getEntity() != nullptr) {
            MathHelper::Vec2 rotation = MathHelper::direction(player.getPosX(), player.getPosY(), player.getPosZ(), closest.getPosX(), closest.getPosY(), closest.getPosZ());
            player.setRotationYaw((float)rotation.x);
            player.setRotationPitch((float)rotation.y);
        }
}

void AimBot::renderSettings() {
    ImGui::SliderFloat("range", &range, 0, 6);
    ImGui::Checkbox("Only while clicking", &onlyOnClick);
}
