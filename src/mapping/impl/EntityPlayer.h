//
// Created by somepineaple on 2/1/22.
//

#ifndef PHANTOM_ENTITYPLAYER_H
#define PHANTOM_ENTITYPLAYER_H

#include "../AbstractClass.h"
#include "../../Phantom.h"
#include "EntityLivingBase.h"


class EntityPlayer : public AbstractClass {
public:
    EntityPlayer(Phantom *phantom, jobject player);

    jdouble getPosX();
    jdouble getPosY();
    jdouble getPosZ();
    jint getId();
    const char *getName();

    EntityLivingBase *toEntityLivingBase();

    void setRotationYaw(jfloat yaw);
    void setRotationPitch(jfloat pitch);
    void setSprinting(jboolean sprinting);

    jdouble getLastTickPosX();
    jfloat getEyeHeight();
    jdouble getLastTickPosZ();
protected:
    jfieldID fdPosX;
    jfieldID fdLastTickPosX;
    jfieldID fdPosY;
    jfieldID fdPosZ;
    jfieldID fdLastTickPosZ;
    jfieldID fdRotationYaw;
    jfieldID fdRotationPitch;
    jmethodID mdGetId;
    jmethodID mdGetName;
    jmethodID mdSetSprinting;
    jmethodID mdGetEyeHeight;

    jobject player;
};


#endif //PHANTOM_ENTITYPLAYER_H
