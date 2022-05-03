//
// Created by somepineaple on 2/21/22.
//

#include "EntityRenderer.h"

EntityRenderer::EntityRenderer(Phantom *phantom, jobject entityRenderer) : AbstractClass(phantom, "EntityRenderer") {
    fdPointedEntity = getFieldID("pointedEntity");

    this->entityRenderer = entityRenderer;
}

jobject EntityRenderer::getPointedEntity() {
    return getObject(entityRenderer, fdPointedEntity);
}

void EntityRenderer::setPointedEntity(jobject entity) {
    setObject(entityRenderer, fdPointedEntity, entity);
}

Entity EntityRenderer::getPointedEntityContainer() {
    return Entity(phantom, getPointedEntity());
}

jobject EntityRenderer::getEntityRenderer() {
    return entityRenderer;
}
