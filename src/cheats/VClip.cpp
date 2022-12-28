//
// Created by somepineaple on 2/1/22.
//

#include "VClip.h"

#include <net/minecraft/entity/EntityPlayerSP.h>
#include <imgui.h>
#include "../utils/ImGuiUtils.h"
#include "../utils/MathHelper.h"


VClip::VClip(Phantom *phantom) : Cheat("VClip", "Set the players position") {
    this->phantom = phantom;

    teleport = true;
    type = false;
    getPosition = false;

    x = 0;
    y = 0;
    z = 0;
}

void VClip::run(Minecraft *mc) {
    EntityPlayerSP player = mc->getPlayerContainer();

    if(getPosition) {
        getPosition = false;
        x = player.getPosX();
        y = player.getPosY();
        z = player.getPosZ();
    }

    if(teleport) {
        if(!type)
            player.setPosition(player.getPosX()+ (double) x, player.getPosY()+ (double) y, player.getPosZ()+ (double) z); // y pos broken?
        else
            player.setPosition(x, y, z);
        teleport = false;
    }
}

void VClip::reset(Minecraft *mc) {
    teleport = true;
}

void VClip::renderSettings() {
    ImGui::Checkbox("Absolute", &type);
    ImGui::SameLine();
    ImGuiUtils::drawHelper("Absolute position will set the players position to world x,y,z coordinates"
                           "If Absolute position is false, the player will be teleported x,y,z relative to the plaeyrs current position");

    ImGui::SliderFloat("x", &x, -10, 10, "%.5f");
    ImGui::SliderFloat("y", &y, -10, 10, "%.5f");
    ImGui::SliderFloat("z", &z, -10, 10, "%.5f");

    if(ImGui::Button("Get position"))
        getPosition = true;

    if(ImGui::Button("Teleport"))
        teleport = true;
}
