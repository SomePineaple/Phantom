//
// Created by somepineaple on 2/1/22.
//

#include "VClip.h"

#include <net/minecraft/entity/EntityPlayerSP.h>
#include <imgui.h>
#include "../utils/MathHelper.h"


VClip::VClip(Phantom *phantom) : Cheat("VClip", "Change the size of vclip's") {
    this->phantom = phantom;

    x = 0;
    y = 0;
    z = 0;
    teleport = true;
}

void VClip::run(Minecraft *mc) {
    if(teleport) {
        EntityPlayerSP player = mc->getPlayerContainer();
        player.setPosition(player.getPosX()+x,player.getPosY()+y, player.getPosZ()+z); // y pos broken?
        teleport = false;
    }
}

void VClip::reset(Minecraft *mc) {
    teleport = true;
}

void VClip::renderSettings() {
    ImGui::SliderFloat("X", &x, -10, 10, "%.2f");
    ImGui::SliderFloat("y", &y, -10, 10, "%.2f");
    ImGui::SliderFloat("z", &z, -10, 10, "%.2f");
    if(ImGui::Button("Teleport"))
        teleport = true;
}
