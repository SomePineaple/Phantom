//
// Created by somepineaple on 2/1/22.
//

#include "EntityPlayer.h"

EntityPlayer::EntityPlayer(Phantom *phantom, jobject player) : AbstractClass(phantom, "PlayerSP") {
    this->player = player;
    //Get all the field and method IDs for EntityPlayerSP that we want (mappings are for 1.12)
    fdPosX = getFieldID("x");
    fdPosY = getFieldID("y");
    fdPosZ = getFieldID("z");
    fdRotationYaw = getFieldID("yaw");
    fdRotationPitch = getFieldID("pitch");
    mdGetId = getMethodID("getID");
    mdGetName = getMethodID("getName");
    mdSetSprinting = getMethodID("setSprint");
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
