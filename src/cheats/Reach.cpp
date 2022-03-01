//
// Created by somepineaple on 2/21/22.
//

#include "Reach.h"

#include <java/util/JavaList.h>
#include <net/minecraft/client/multiplayer/WorldClient.h>
#include "../vendor/imgui/imgui.h"

Reach::Reach(Phantom *phantom) : Cheat("Reach", "Long arm hack") {
    reach = 3;
    this->phantom = phantom;
}

void Reach::renderSettings() {
    ImGui::SliderFloat("Reach: Reach", &reach, 3, 6);
}

void Reach::run(Minecraft *mc) {
    if (!enabled)
        return;

    Entity *renderViewEntity = mc->getRenderViewEntityContainer();
    EntityRenderer *entityRenderer = mc->getEntityRendererContainer();
    Vec3 *hitVec;
    Entity *ridingEntity;

    if (renderViewEntity != nullptr) {
        float partialTicks = mc->getTimerContainer()->getPartialTicks();

        double var2 = reach;
        double var4 = var2;

        Vec3 *var6 = mc->getRenderViewEntityContainer()->getPositionEyesContainer(partialTicks);
        Vec3 *var7 = renderViewEntity->getLookContainer(partialTicks);
        Vec3 *var8 = var6->addVectorContainer(var7->getXCoord() * var2, var7->getYCoord() * var2, var7->getZCoord() * var2);
        entityRenderer->setPointedEntity(nullptr);
        Vec3 *var9 = nullptr;
        float var10 = 1;
        AxisAlignedBB *boundingBox = renderViewEntity->getEntityBoundingBoxContainer();
        JavaList *var11 = mc->getWorldContainer()->getEntitiesWithinAABBExcluding(renderViewEntity->getEntity(), boundingBox->getAddCoordContainer(var7->getXCoord() * var2, var7->getYCoord() * var2, var7->getZCoord() * var2)->expand(var10, var10, var10));
        double var12 = var4;

        for (int var14 = 0; var14 < var11->size(); var14++) {
            auto *var15 = new Entity(mc->getPhantom(), var11->get(var14));

            if (var15->canBeCollidedWith()) {
                float var16 = var15->getCollisionBorderSize();
                AxisAlignedBB *var17 = var15->getEntityBoundingBoxContainer()->getExpandContainer(var16, var16, var16);
                MovingObjectPosition *var18 = var17->getCalculateInterceptContainer(var6->getVec3(), var8->getVec3());
                if (var18 != nullptr)
                    hitVec = var18->getHitVecContainer();

                if (var17->isVecInside(var6->getVec3())) {
                    if (0 <= var12) {
                        entityRenderer->setPointedEntity(var15->getEntity());
                        var9 = var18 == nullptr ? var6 : hitVec;
                        var12 = 0;
                    }
                } else if (var18 != nullptr) {
                    double var19 = var6->distanceTo(hitVec->getVec3());
                    if (var19 < var12 || var12 == 0) {
                        ridingEntity = renderViewEntity->getRidingEntityContainer();
                        if (ridingEntity != nullptr && var15->getId() == ridingEntity->getId()) {
                            if (var12 == 0) {
                                entityRenderer->setPointedEntity(var15->getEntity());
                                var9 = hitVec;
                            }
                        } else {
                            entityRenderer->setPointedEntity(var15->getEntity());
                            var9 = hitVec;
                            var12 = var19;
                        }
                    }
                }
            }
        }

        if (entityRenderer->getPointedEntityContainer() != nullptr && var12 > 3) {
            jclass MovingObjectPosition = mc->getClass("net.minecraft.util.MovingObjectPosition");
            jmethodID movingObjectPositionConstructor = phantom->getEnv()->GetMethodID(MovingObjectPosition, "<init>", "(Lnet/minecraft/entity/Entity;Lnet/minecraft/util/Vec3;)V");
            mc->setObjectMouseOver(phantom->getEnv()->NewObject(MovingObjectPosition, movingObjectPositionConstructor, entityRenderer->getPointedEntity(), var9->getVec3()));
        }
    }
}
