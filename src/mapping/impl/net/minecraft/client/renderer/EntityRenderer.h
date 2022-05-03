//
// Created by somepineaple on 2/21/22.
//

#ifndef PHANTOM_ENTITYRENDERER_H
#define PHANTOM_ENTITYRENDERER_H


#include "../../../../../AbstractClass.h"
#include <net/minecraft/entity/Entity.h>

class EntityRenderer : public AbstractClass {
public:
    EntityRenderer(Phantom *phantom, jobject entityRenderer);

    jobject getPointedEntity();
    void setPointedEntity(jobject entity);

    Entity getPointedEntityContainer();
    jobject getEntityRenderer();
private:
    jfieldID fdPointedEntity;

    jobject entityRenderer;
};


#endif //PHANTOM_ENTITYRENDERER_H
