#include "HitBox.h"

#include <net/minecraft/entity/EntityPlayerSP.h>
#include <imgui.h>
#include "../utils/ImGuiUtils.h"
#include "../utils/MathHelper.h"


HitBox::HitBox(Phantom *phantom) : Cheat("HitBox", "Change the size of hitbox's") {
    this->phantom = phantom;


    canBeResetTemporaryVariableThatsWhyTheNameIsSoLongSoIWantToFixThisMore = false;
    showHitbox = false;
    reload = true;
    devSize = false;
    selfWidth = 0.6;
    selfHeight = 1.8;
    oldSelfWidth = 0.6;
    oldSelfHeight = 1.8;
    scale = 0;
}

void HitBox::run(Minecraft *mc) {
    canBeResetTemporaryVariableThatsWhyTheNameIsSoLongSoIWantToFixThisMore = true;

    if(devSize)
        scale = -10;
    else
        scale = 0;

    EntityPlayerSP player = mc->getPlayerContainer();
    player.setSelfWidth(selfWidth);
    player.setSelfHeight(selfHeight);

    if((player.getSelfWidth() != oldSelfWidth || player.getSelfHeight() != oldSelfHeight)) {// need to check if there is a difference since getting the players position causes lag
        oldSelfWidth = selfWidth;
        oldSelfHeight = selfHeight;
        if (reload)
            player.setPosition(player.getPosX(), player.getPosY(), player.getPosZ()); // there may be a better way to do it like maybe an actaull update method or something. but this works for now ig.
    }

    /* if(showHitbox) */
    /* player. */
}

void HitBox::reset(Minecraft *mc) {
    if(canBeResetTemporaryVariableThatsWhyTheNameIsSoLongSoIWantToFixThisMore) {
        EntityPlayerSP player = mc->getPlayerContainer();

        // probably faster not checking for differences here since its only once once every so often
        player.setSelfWidth(0.6);
        player.setSelfHeight(1.8);
        oldSelfWidth = 0.6;
        oldSelfHeight = 1.8;

        if(reload)
            player.setPosition(player.getPosX(), player.getPosY(), player.getPosZ());
        canBeResetTemporaryVariableThatsWhyTheNameIsSoLongSoIWantToFixThisMore = false; // i will make this sort of one time reset() call global in Phantom.* but ill have to modify it quite heavily so ill leave that fora  bit since Hitbox is really the only thing that needs to be reset once as of now
    }
}

void HitBox::renderSettings() {
    ImGui::Checkbox("Show hitbox", &showHitbox);

    if(ImGui::CollapsingHeader("Personal Hitbox")) {
        ImGui::Text("You will usually have to update the player (e.g. walk through a block) for changes to take effect");

        ImGui::Checkbox("Reload", &reload);
        ImGui::SameLine();
        ImGuiUtils::drawHelper("Weather or not to instantly update the hitbox");

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

}
