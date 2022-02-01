//
// Created by somepineaple on 2/1/22.
//

#ifndef PHANTOM_ENTITYPLAYER_H
#define PHANTOM_ENTITYPLAYER_H

#include "../AbstractClass.h"
#include "../../Phantom.h"


class EntityPlayer : public AbstractClass {
public:
    EntityPlayer(Phantom *phantom, jobject player);

    jdouble getPosX();
    jdouble getPosY();
    jdouble getPosZ();
    jint getId();
    const char *getName();

    void setRotationYaw(jfloat yaw);
    void setRotationPitch(jfloat pitch);
    void setSprinting(jboolean sprinting);
protected:
    jfieldID fdPosX;
    jfieldID fdPosY;
    jfieldID fdPosZ;
    jfieldID fdRotationYaw;
    jfieldID fdRotationPitch;
    jmethodID mdGetId;
    jmethodID mdGetName;
    jmethodID mdSetSprinting;

    jobject player;
};


#endif //PHANTOM_ENTITYPLAYER_H
