//
// Created by somepineaple on 2/1/22.
//

#ifndef PHANTOM_ENTITYLIVINGBASE_H
#define PHANTOM_ENTITYLIVINGBASE_H

#include "../../../../AbstractClass.h"

class EntityLivingBase : public AbstractClass {
public:
    EntityLivingBase(Phantom *phantom, jobject entity);

    jdouble getPosX();
    jdouble getPosY();
    jdouble getPosZ();

    jdouble getLastTickPosX();
    jfloat getEyeHeight();
    jdouble getLastTickPosZ();

    jint getId();
    const char * getName();

    jobject getEntityLivingBase();
private:
    jfieldID fdPosX;
    jfieldID fdLastTickPosX;
    jfieldID fdPosY;
    jfieldID fdPosZ;
    jfieldID fdLastTickPosZ;
    jmethodID mdGetEyeHeight;
    jmethodID mdGetId;
    jmethodID mdGetName;

    jobject entity;
};


#endif //PHANTOM_ENTITYLIVINGBASE_H
