//
// Created by somepineaple on 2/1/22.
//

#include "ReverseHitbox.h"

#include <net/minecraft/entity/EntityPlayerSP.h>
#include <imgui.h>
#include "../utils/MathHelper.h"


ReverseHitbox::ReverseHitbox(Phantom *phantom) : Cheat("Reverse Hitbox", "Change the size of your own hitbox") {
    this->phantom = phantom;

    defaultHitbox = true;
    width = 0.6;
    height = 1.8;
}

void ReverseHitbox::run(Minecraft *mc) {
    if(defaultHitbox) {
        width = 0.6;
        height = 1.8;
        return;
    }

    EntityPlayerSP player = mc->getPlayerContainer();
    player.setWidth(width);
    player.setHeight(height);

}

void ReverseHitbox::renderSettings() {
    ImGui::Checkbox("Default Hitbox Size", &defaultHitbox);
    ImGui::SliderFloat("Hitbox width (0.6)", &width, 0, 10, "%.1f");
    ImGui::SliderFloat("Hitbox height (1.8)", &height, 0, 10, "%.1f");
}
