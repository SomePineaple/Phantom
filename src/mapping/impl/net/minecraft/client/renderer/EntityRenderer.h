//
// Created by somepineaple on 2/21/22.
//

#ifndef PHANTOM_ENTITYRENDERER_H
#define PHANTOM_ENTITYRENDERER_H


#include "../../../../../AbstractClass.h"
#include "../../entity/Entity.h"

class EntityRenderer : public AbstractClass {
public:
    EntityRenderer(Phantom *phantom, jobject entityRenderer);

    jobject getPointedEntity();
    void setPointedEntity(jobject entity);

    Entity *getPointedEntityContainer();
private:
    jfieldID fdPointedEntity;

    jobject entityRenderer;
};


#endif //PHANTOM_ENTITYRENDERER_H
