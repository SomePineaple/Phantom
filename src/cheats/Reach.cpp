//
// Created by somepineaple on 2/21/22.
//

#include "Reach.h"

#include <java/util/JavaList.h>
#include <net/minecraft/client/multiplayer/WorldClient.h>
#include "../vendor/imgui/imgui.h"

Reach::Reach() : Cheat("Reach", "Long arm hack") {
    reach = 3;
}

void Reach::renderSettings() {
    ImGui::SliderFloat("Reach: Reach", &reach, 3, 6);
}

void Reach::run(Minecraft *mc) {
    Entity *renderViewEntity = mc->getRenderViewEntityContainer();
    EntityRenderer *entityRenderer = mc->getEntityRendererContainer();

    if (renderViewEntity != nullptr) {
        float partialTicks = mc->getTimerContainer()->getPartialTicks();

        double var2 = reach;
        double var4 = var2;

        Vec3 *var6 = mc->getRenderViewEntityContainer()->getPositionEyesContainer(partialTicks);
        Vec3 *var7 = renderViewEntity->getLookContainer(partialTicks);
        Vec3 *var8 = var6->addVectorContainer(var7->getXCoord() * var2, var7->getYCoord() * var2, var7->getZCoord() * var2);
        entityRenderer->setPointedEntity(nullptr);
        float var10 = 1;
        AxisAlignedBB *boundingBox = renderViewEntity->getEntityBoundingBoxContainer();
        JavaList *var11 = mc->getWorldContainer()->getEntitiesWithinAABBExcluding(renderViewEntity->getEntity(), boundingBox->getAddCoordContainer(var7->getXCoord() * var2, var7->getYCoord() * var2, var7->getZCoord() * var2)->expand(var10, var10, var10));
        double var12 = var4;

        for (int var14 = 0; var14 < var11->size(); var14++) {
            auto *var15 = new Entity(mc->getPhantom(), var11->get(var14));

            if (var15->canBeCollidedWith()) {

            }
        }
    }
}
