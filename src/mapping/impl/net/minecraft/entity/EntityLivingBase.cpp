//
// Created by somepineaple on 2/1/22.
//

#include "EntityLivingBase.h"

EntityLivingBase::EntityLivingBase(Phantom *phantom, jobject entity) : AbstractClass(phantom, "EntityLivingBase") {
    this->entity = entity;

    //Get all the field and method IDs for Entity that we want (mappings are for 1.12)
    fdPosX = getFieldID("x");
    fdLastTickPosX = getFieldID("lastTickPosX");
    fdPosY = getFieldID("y");
    fdPosZ = getFieldID("z");
    fdLastTickPosZ = getFieldID("lastTickPosZ");
    mdGetEyeHeight = getMethodID("getEyeHeight");
    mdGetId = getMethodID("getID");
    mdGetName = getMethodID("getName");
}

jdouble EntityLivingBase::getPosX() {
    return getDouble(entity, fdPosX);
}

jdouble EntityLivingBase::getPosY() {
    return getDouble(entity, fdPosY);
}

jdouble EntityLivingBase::getPosZ() {
    return getDouble(entity, fdPosZ);
}

jint EntityLivingBase::getId() {
    return getInt(entity, mdGetId);
}

const char *EntityLivingBase::getName() {
    //Needs to get the name as a jstring, then convert that to something usable
    auto str = (jstring)getObject(entity, mdGetName);
    jboolean notTrue = false;
    return phantom->getEnv()->GetStringUTFChars(str, &notTrue);
}

jdouble EntityLivingBase::getLastTickPosX() {
    return getDouble(entity, fdLastTickPosX);
}

jdouble EntityLivingBase::getLastTickPosZ() {
    return getDouble(entity, fdLastTickPosZ);
}

jfloat EntityLivingBase::getEyeHeight() {
    return getFloat(entity, mdGetEyeHeight);
}

jobject EntityLivingBase::getEntityLivingBase() {
    return entity;
}
