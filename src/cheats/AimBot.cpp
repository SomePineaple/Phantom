//
// Created by somepineaple on 1/30/22.
//

#include "AimBot.h"

#include "../mapping/impl/Entity.h"
#include "../mapping/impl/WorldClient.h"
#include "../mapping/impl/EntityPlayerSP.h"
#include "../utils/MathHelper.h"
#include "../utils/JvmUtils.h"
#include "../vendor/imgui/imgui.h"

AimBot::AimBot(Phantom *phantom) : Cheat("AimBot","Automatically puts cursor over the nearest entity. "
                                                   "Please note: there is no antibot, and also this is not aim assist. "
                                                   "This will probably insta-ban on most servers with a semi-decent "
                                                   "anticheat.") {
    this->phantom = phantom;

    range = 3.5;
}

void AimBot::run(Minecraft *mc) {
    if (!enabled)
        return;

    EntityPlayerSP *player = mc->getPlayerContainer();
    WorldClient *world = mc->getWorldContainer();

    float closestDist = range;

    // Get all the entities, calculate the closest one
    JavaSet *entities = world->getEntities();
    Entity *closest = nullptr;
    for (int i = 0; i < entities->size(); i++) {
        auto * entity = new Entity(phantom, mc, entities->get(i));
        if (entity->getId() != player->getId()) {
            auto newDist = (float)MathHelper::distance(entity->getPosX(), entity->getPosY(), entity->getPosZ(), player->getPosX(), player->getPosY(), player->getPosZ());
            if (newDist < closestDist) {
                closestDist = newDist;
                closest = entity;
            }
        }
    }

    // If there is an entity in range, look at it
    if (closest != nullptr) {
        double *rotation = MathHelper::direction(player->getPosX(), player->getPosY(), player->getPosZ(), closest->getPosX(), closest->getPosY(), closest->getPosZ());
        player->setRotationYaw((float)rotation[0]);
        player->setRotationPitch((float)rotation[1]);
    }
}

void AimBot::renderSettings() {
    ImGui::SliderFloat("AimBot: range", &range, 0, 6);
}
