#include "STap.h"

#include <imgui.h>
#include "../utils/MathHelper.h"
#include <net/minecraft/entity/player/EntityPlayer.h>
#include <java/util/JavaList.h>
#include <net/minecraft/entity/EntityPlayerSP.h>
#include <net/minecraft/client/multiplayer/WorldClient.h>
#include <cmath>

STap::STap(Phantom *phantom) : Cheat("STap", "Get Crazy Combo's bro") {
    engageDistance = 2.7;
    disengageDistance = 3.0;
    holding = false;

    this->phantom = phantom;

    numIntersections = 0;
}

void STap::renderSettings() {
    ImGui::SliderFloat("Engage Distance", &engageDistance, 0.0, 4.0);
    ImGui::SliderFloat("Disengage Distance", &disengageDistance, 0.0, 4.0);

    ImGui::Text("%d, %.2f", numIntersections, dist);

    if (disengageDistance < engageDistance)
        disengageDistance = engageDistance;
}

void STap::run(Minecraft *mc) {
    EntityPlayerSP player = mc->getPlayerContainer();
    /*
    MathHelper::Vec3 rayOrigin {
        player.getPosX(), player.getPosY() + player.getEyeHeight(), player.getPosZ()
    };

    double xzLen = cos(player.getRotationPitch());
    MathHelper::Vec3 rayDir {
        xzLen * cos(player.getRotationYaw()),
        sin(player.getRotationPitch()),
        xzLen * sin(-player.getRotationYaw())
    };

    MathHelper::Ray lookRay {
        rayOrigin,
        MathHelper::normalize(rayDir)
    };*/

    JavaList players = mc->getWorldContainer().getPlayers();
    if (players.getList() == nullptr)
        return;

    holding = false;

    numIntersections = 0;
    for (int i = 0; i < players.size(); i++) {
        EntityPlayer enemyPlayer(phantom, players.get(i));
        if (enemyPlayer.getId() != player.getId()) {
            double distance = MathHelper::distance(enemyPlayer.getPosX(), enemyPlayer.getPosY(), enemyPlayer.getPosZ(), player.getPosX(), player.getPosY(), player.getPosZ());
            if (distance > engageDistance && distance < disengageDistance) {
                holding = true;
                dist = distance;
            }
        }
    }

    KeyBinding keyBindBack = mc->getGameSettingsContainer().getKeyBindBackContainer();
    if (holding) {
        keyBindBack.setKeyBindState(keyBindBack.getKeyCode(), true);
    } else {
        keyBindBack.setKeyBindState(keyBindBack.getKeyCode(), false);
    }
}
