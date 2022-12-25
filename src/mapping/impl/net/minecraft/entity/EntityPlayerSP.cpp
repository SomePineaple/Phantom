//
// Some of this code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#include "EntityPlayerSP.h"

#include <net/minecraft/client/Minecraft.h>

EntityPlayerSP::EntityPlayerSP(Phantom * phantom, Minecraft * mc) : AbstractClass(phantom, "PlayerSP") {
	this->mc = mc;

	//Get all the field and method IDs for EntityPlayerSP that we want (mappings are for 1.12)
	fdPosX = getFieldID("x");
	fdPosY = getFieldID("y");
	fdPosZ = getFieldID("z");
	fdRotationYaw = getFieldID("yaw");
	fdRotationPitch = getFieldID("pitch");
    /* fdGetItemInUse = getFieldID("itemInUse"); */
    /* fdGetEquipment = getFieldID("equipment"); */
    fdSelfWidth = getFieldID("width");
    fdSelfHeight = getFieldID("height");
	mdGetId = getMethodID("getID");
	mdGetName = getMethodID("getName");
	mdSetSprinting = getMethodID("setSprint");
    mdGetEyeHeight = getMethodID("getEyeHeight");
    mdGetDisplayName = getMethodID("getDisplayName");

    jclass IChatComponent = getClass("net.minecraft.util.IChatComponent");
    mdIChatComponentGetFmtTxt = phantom->getEnv()->GetMethodID(IChatComponent, "func_150254_d", "()Ljava/lang/String;");
}

jdouble EntityPlayerSP::getPosX() {
	return getDouble(mc->getPlayer(), fdPosX);
}

jdouble EntityPlayerSP::getPosY() {
	return getDouble(mc->getPlayer(), fdPosY);
}

jdouble EntityPlayerSP::getPosZ() {
	return getDouble(mc->getPlayer(), fdPosZ);
}

jint EntityPlayerSP::getId() {
	return getInt(mc->getPlayer(), mdGetId);
}

const char * EntityPlayerSP::getName() {
	//Needs to get the name as a jstring, then convert that to something usable
	auto str = (jstring)getObject(mc->getPlayer(), mdGetName);
    jboolean notTrue = false;
	return phantom->getEnv()->GetStringUTFChars(str, &notTrue);
}

void EntityPlayerSP::setRotationYaw(jfloat yaw) {
	setFloat(mc->getPlayer(), fdRotationYaw, yaw);
}

void EntityPlayerSP::setRotationPitch(jfloat pitch) {
	setFloat(mc->getPlayer(), fdRotationPitch, pitch);
}

void EntityPlayerSP::setSprinting(jboolean sprinting) {
	callMethod(mc->getPlayer(), mdSetSprinting, sprinting);
}

jfloat EntityPlayerSP::getEyeHeight() {
    return getFloat(mc->getPlayer(), mdGetEyeHeight);
}

jfloat EntityPlayerSP::getRotationYaw() {
    return getFloat(mc->getPlayer(), fdRotationYaw);
}

jfloat EntityPlayerSP::getRotationPitch() {
    return getFloat(mc->getPlayer(), fdRotationPitch);
}

const char *EntityPlayerSP::getFormattedDisplayName() {
    jobject displayName = getObject(mc->getPlayer(), mdGetDisplayName);
    auto str = (jstring) getObject(displayName, mdIChatComponentGetFmtTxt);

    jboolean notTrue = false;
    return phantom->getEnv()->GetStringUTFChars(str, &notTrue);
}

/* const char *EntityPlayerSP::getItemInUse() { */
    /* auto str = (jstring) getObject(mc->getPlayer(), fdGetItemInUse); */
    /* jboolean notTrue = false; */
    /* return phantom->getEnv()->GetStringUTFChars(str, &notTrue); */
/* } */

void EntityPlayerSP::setSelfWidth(jfloat width) {
    setFloat(mc->getPlayer(), fdSelfWidth, width);
}

void EntityPlayerSP::setSelfHeight(jfloat height) {
    setFloat(mc->getPlayer(), fdSelfHeight, height);
}

/* const char *EntityPlayerSP::getClickedItem() { */
/*     auto item = (jstring)getObject(mc->getPlayer(), fdGetClickedItem); */
/*     jboolean notTrue = false; */
/*     return phantom->getEnv()->GetStringUTFChars(item, &notTrue); */
/* } */

jobject EntityPlayerSP::getEntityPlayerSP() {
    return mc->getPlayer();
}
