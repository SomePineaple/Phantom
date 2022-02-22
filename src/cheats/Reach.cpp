//
// Created by somepineaple on 2/21/22.
//

#include "Reach.h"

#include "../vendor/imgui/imgui.h"
#include "../mapping/impl/net/minecraft/entity/Entity.h"

Reach::Reach() : Cheat("Reach", "Long arm hack") {
    reach = 3;
}

void Reach::renderSettings() {
    ImGui::SliderFloat("Reach: Reach", &reach, 3, 6);
}

void Reach::run(Minecraft *mc) {
    Entity *renderViewEntity = mc->getRenderViewEntityContainer();

    if (renderViewEntity != nullptr) {
        float partialTicks = mc->getTimerContainer()->getPartialTicks();

        double var2 = reach;
        double var4 = var2;

        Vec3 *var6 = mc->getRenderViewEntityContainer()->getPositionEyesContainer(partialTicks);
        Vec3 *var7 = renderViewEntity->getLookContainer(partialTicks);
        Vec3 *var8 = var6->addVectorContainer(var7->getXCoord() * var2, var7->getYCoord() * var2, var7->getZCoord() * var2);
    }
}
