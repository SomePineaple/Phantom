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

    showHitbox = false;
    devSize = false;
    selfWidth = 0.6;
    selfHeight = 1.8;
    scale = 0;

    horizontal = 0.6;
    vertical = 0.6;
}

void Hitbox::run(Minecraft *mc) {

    if(devSize)
        scale = -10;
    else
        scale = 0;

    EntityPlayerSP player = mc->getPlayerContainer();
    player.setSelfWidth(selfWidth);
    player.setSelfHeight(selfHeight);
    // TODO: find a way to reload/update player/world to update hitbox

    /* player.setCurBlockDamageMP(1.0F); */

    /* if(showHitbox) */
        /* player. */

    player.setVelocity(horizontal, vertical, 1);

}

void Hitbox::reset(Minecraft *mc) {
    EntityPlayerSP player = mc->getPlayerContainer();
    player.setSelfWidth(0.6);
    player.setSelfHeight(1.8);
}

void Hitbox::renderSettings() {
    ImGui::Checkbox("Show hitbox", &showHitbox);

    if(ImGui::CollapsingHeader("Personal")) {
        ImGui::Text("You will usually have to update the player (e.g. walk through a block) for changes to take effect");

        ImGui::Checkbox("Allow Hitbox size lower than 0", &devSize);
        ImGui::SameLine();
        ImGuiUtils::drawHelper("WARNING: very dangerous; should only be used for testing purposes!!!!");

        ImGui::SliderFloat("Hitbox width", &selfWidth, scale, 10, "%.1f");
        ImGui::SliderFloat("Hitbox height", &selfHeight, scale, 10, "%.1f");

        if(ImGui::Button("Default Hitbox Size")) {
            selfWidth = 0.6;
            selfHeight = 1.8;
        }
        if(ImGui::Button("Phase")) {  // should phase be a seperate cheat even thought it uses hitbox's?
            selfWidth = 0;
            selfHeight = 0;
        }

    }

    ImGui::SliderFloat("Horizontal velocity", &horizontal, 0, 100, "%.5f");
    ImGui::SliderFloat("Vertical velocity", &vertical, 0, 100, "%.5f");
}
