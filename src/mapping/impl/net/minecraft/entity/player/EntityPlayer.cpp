//
// Created by somepineaple on 2/1/22.
//

#include "EntityPlayer.h"

EntityPlayer::EntityPlayer(Phantom *phantom, jobject player) :  AbstractClass(phantom, "EntityPlayer") {
    this->player = player;
    //Get all the field and method IDs for EntityPlayerSP that we want (mappings are for 1.12)
    fdPosX = getFieldID("x");
    fdLastTickPosX = getFieldID("lastTickPosX");
    fdPosY = getFieldID("y");
    fdPosZ = getFieldID("z");
    fdLastTickPosZ = getFieldID("lastTickPosZ");
    fdRotationYaw = getFieldID("yaw");
    fdRotationPitch = getFieldID("pitch");
    mdGetId = getMethodID("getID");
    mdGetName = getMethodID("getName");
    mdSetSprinting = getMethodID("setSprint");
    mdGetEyeHeight = getMethodID("getEyeHeight");
}

jdouble EntityPlayer::getPosX() {
    return getDouble(player, fdPosX);
}

jdouble EntityPlayer::getPosY() {
    return getDouble(player, fdPosY);
}

jdouble EntityPlayer::getPosZ() {
    return getDouble(player, fdPosZ);
}

jint EntityPlayer::getId() {
    return getInt(player, mdGetId);
}

const char * EntityPlayer::getName() {
    //Needs to get the name as a jstring, then convert that to something usable
    auto str = (jstring)getObject(player, mdGetName);
    jboolean notTrue = false;
    return phantom->getEnv()->GetStringUTFChars(str, &notTrue);
}

void EntityPlayer::setRotationYaw(jfloat yaw) {
    setFloat(player, fdRotationYaw, yaw);
}

void EntityPlayer::setRotationPitch(jfloat pitch) {
    setFloat(player, fdRotationPitch, pitch);
}

void EntityPlayer::setSprinting(jboolean sprinting) {
    callMethod(player, mdSetSprinting, sprinting);
}

EntityLivingBase *EntityPlayer::toEntityLivingBase() {
    return new EntityLivingBase(phantom, player);
}

jfloat EntityPlayer::getEyeHeight() {
    return getFloat(player, mdGetEyeHeight);
}

jdouble EntityPlayer::getLastTickPosX() {
    return getDouble(player, fdLastTickPosX);
}

jdouble EntityPlayer::getLastTickPosZ() {
    return getDouble(player, fdLastTickPosZ);
}
