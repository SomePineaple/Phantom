//
// Created by somepineaple on 2/1/22.
//

#include "Velocity.h"

#include <net/minecraft/entity/EntityPlayerSP.h>
#include <imgui.h>
#include <cstdlib>
#include "../utils/MathHelper.h"


Velocity::Velocity(Phantom *phantom) : Cheat("Velocity", "Modifies entities velocity values") {
    this->phantom = phantom;

    chance = 100;

    horizontalMotion = 100;
    verticalMotion = 100;
}

void Velocity::run(Minecraft *mc) {
    EntityPlayerSP player = mc->getPlayerContainer();

    if(player.getMaxHurtTime() > 0 && player.getHurtTime() ==player.getMaxHurtTime()) {
        if(chance != 100 && chance < 1 + (rand() % 100))
            return;

        /* player.setVelocity(0.4*(horizontalVelocity/100), 0.36*(verticalVelocity/100)); // dont know defaults yet0.4 and 0.36 are default not sprinting on normal ground knockback since i havnt gotten the velocity yet */
        player.setMotionHorizontal((double)horizontalMotion/100.0);
        player.setMotionY((double)verticalMotion/100.0);
    }
}

void Velocity::reset(Minecraft *mc) {}

void Velocity::renderSettings() {
    ImGui::SliderFloat("Chance (%)", &chance, 0, 100, "%1.0f");

    ImGui::SliderFloat("horizontal (%)", &horizontalMotion, 0, 100, "%1.0f");
    ImGui::SliderFloat("vertical (%)", &verticalMotion, 0, 100, "%1.0f");
}
