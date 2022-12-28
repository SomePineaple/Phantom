//
// Created by somepineaple on 2/1/22.
//

#include "Velocity.h"

#include <net/minecraft/entity/EntityPlayerSP.h>
#include <imgui.h>
#include "../utils/ImGuiUtils.h"
#include "../utils/MathHelper.h"


Velocity::Velocity(Phantom *phantom) : Cheat("Velocity", "Modifies entities velocity values") {
    this->phantom = phantom;

    constantHorizontal = 0;
    constantVertical = 0;
}

void Velocity::run(Minecraft *mc) {
    EntityPlayerSP player = mc->getPlayerContainer();

    player.setVelocity((double)constantHorizontal, (double)constantVertical);
}

void Velocity::reset(Minecraft *mc) {
    /* EntityPlayerSP player = mc->getPlayerContainer(); */

    /* player.setVelocity(0, 0); // dont know how to reset this 0 is temporary */
}

void Velocity::renderSettings() {
    ImGui::SliderFloat("Chance", &chance, 0, 100, "%1f");

    if(ImGui::CollapsingHeader("Constant Velocity")) {
        ImGui::SliderFloat("Horizontal", &constantHorizontal, -10, 10, "%.5f");
        ImGui::SliderFloat("Vertical", &constantVertical, -10, 10, "%.5f");
    }
    ImGui::SameLine();
    ImGuiUtils::drawHelper("Defines the velocity of the player"); // when "Constant Velocity" Header drops this text gets appended to the lastImGui thing, it should stay on the Header?
}
