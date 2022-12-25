//
// Created by somepineaple on 2/1/22.
//

#include "Hitbox.h"

#include <net/minecraft/entity/EntityPlayerSP.h>
#include <imgui.h>
#include "../utils/ImGuiUtils.h"
#include "../utils/MathHelper.h"


Hitbox::Hitbox(Phantom *phantom) : Cheat("Hitbox", "Change the size of hitbox's") {
    this->phantom = phantom;

    devSize = false;
    selfWidth = 0.6;
    selfHeight = 1.8;
    scale = 0;
}

void Hitbox::run(Minecraft *mc) {
    if(devSize)
        scale = -10;
    else
        scale = 0;

    EntityPlayerSP player = mc->getPlayerContainer();
    player.setSelfWidth(selfWidth);
    player.setSelfHeight(selfHeight);

}

void Hitbox::renderSettings() {
    if(ImGui::CollapsingHeader("Personal")) {
        ImGui::Checkbox("Allow Hitbox size lower than 0", &devSize);
        ImGui::SameLine();
        ImGuiUtils::drawHelper("WARNING: very dangerous; should only be used for testing purposes!!!!");
        if(ImGui::Button("Phase")) {  // should phase be a seperate cheat even thought it uses hitbox's?
            selfWidth = 0;
            selfHeight = 0;
        }
        if(ImGui::Button("Default Hitbox Size")) {
            selfWidth = 0.6;
            selfHeight = 1.8;
        }
        ImGui::SliderFloat("Hitbox width", &selfWidth, scale, 10, "%.1f");
        ImGui::SliderFloat("Hitbox height", &selfHeight, scale, 10, "%.1f");

    }
}
