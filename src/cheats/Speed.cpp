//
// Created by somepineaple on 2/1/22.
//

#include "Speed.h"

#include <net/minecraft/entity/EntityPlayerSP.h>
#include <imgui.h>
#include "../utils/MathHelper.h"

Speed::Speed(Phantom *phantom) : Cheat("Speed", "Modify player speed") {
    this->phantom = phantom;

    speed = 0.2;
}

void Speed::run(Minecraft *mc) {
    EntityPlayerSP player = mc->getPlayerContainer();

    player.setSpeed(speed);
}

void Speed::reset(Minecraft *mc) {}

void Speed::renderSettings() {
    ImGui::SliderFloat("Speed", &speed, 0, 1, "%.1f");
    if(ImGui::Button("Default"))
        speed = 0.2;
}
