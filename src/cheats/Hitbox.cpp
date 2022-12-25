//
// Created by somepineaple on 2/1/22.
//

#include "Hitbox.h"

#include <net/minecraft/entity/EntityPlayerSP.h>
#include <imgui.h>
#include "../utils/MathHelper.h"


Hitbox::Hitbox(Phantom *phantom) : Cheat("Hitbox", "Change the size of hitbox's") {
    this->phantom = phantom;

    defaultSelfHitbox = true;
    phase = false;
    selfWidth = 0.6;
    selfHeight = 1.8;
}

void Hitbox::run(Minecraft *mc) {

    if(defaultSelfHitbox) {
        selfWidth = 0.6;
        selfHeight = 1.8;
    } else if(phase) {
        selfWidth = 0;
        selfHeight = 0;
    }

    EntityPlayerSP player = mc->getPlayerContainer();
    player.setSelfWidth(selfWidth);
    player.setSelfHeight(selfHeight);

}

void Hitbox::renderSettings() {
    ImGui::Checkbox("Default Hitbox Size", &defaultSelfHitbox);
    ImGui::SliderFloat("Hitbox width (0.6)", &selfWidth, 0, 10, "%.1f");
    ImGui::SliderFloat("Hitbox height (1.8)", &selfHeight, 0, 10, "%.1f");
    ImGui::Checkbox("Phase", &phase); // should phase be a seperate cheat even thought it uses hitbox's?

}
