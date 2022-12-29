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
    fdSelfWidth = getFieldID("width");
    fdSelfHeight = getFieldID("height");
    fdMotionX = getFieldID("motionX");
    fdMotionY = getFieldID("motionY");
    fdMotionZ = getFieldID("motionZ");
    fdHurtTime = getFieldID("hurtTime");
    fdMaxHurtTime = getFieldID("maxHurtTime");
    mdSetPosition = getMethodID("setPosition");
    mdSetVelocity = getMethodID("setVelocity");
    /* mdGetPositionVector = getMethodID("getPositionVector"); */
    /* mdGetLook = getMethodID("getLook"); */
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

/* Vec3 EntityPlayerSP::getPositionVector() { */
/*     return Vec3(phantom, mdGetPositionVector) */
/* } */

/* jobject EntityPlayerSP::getLook(jfloat partialTicks) { */
/*     return getObject(mc->getPlayer(), mdGetLook, partialTicks); */
/* } */

/* Vec3 EntityPlayerSP::getLookContainer(jfloat partialTicks) { */
/*     return Vec3(phantom, getLook(partialTicks)); */
/* } */

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

void EntityPlayerSP::setSelfWidth(jfloat width) {
    setFloat(mc->getPlayer(), fdSelfWidth, width);
}

void EntityPlayerSP::setSelfHeight(jfloat height) {
    setFloat(mc->getPlayer(), fdSelfHeight, height);
}

jfloat EntityPlayerSP::getSelfWidth() {
    return getFloat(mc->getPlayer(), fdSelfWidth);
}

jfloat EntityPlayerSP::getSelfHeight() {
    return getFloat(mc->getPlayer(), fdSelfHeight);
}

void EntityPlayerSP::setMotionHorizontal(jdouble horizontal) {
    horizontal *= getDouble(mc->getPlayer(), fdMotionX);
    setDouble(mc->getPlayer(), fdMotionX, horizontal);
    setDouble(mc->getPlayer(), fdMotionZ, horizontal);
}

void EntityPlayerSP::setMotionY(jdouble motionY) {
    setDouble(mc->getPlayer(), fdMotionY, getDouble(mc->getPlayer(), fdMotionY) * motionY);
}

jint EntityPlayerSP::getHurtTime() {
    return getInt(mc->getPlayer(), fdHurtTime);
}

jint EntityPlayerSP::getMaxHurtTime() {
    return getInt(mc->getPlayer(), fdMaxHurtTime);
}

void EntityPlayerSP::setVelocity(jdouble horizontal, jdouble vertical) {
    callMethod(mc->getPlayer(), mdSetVelocity, horizontal, vertical, horizontal);
}

void EntityPlayerSP::setPosition(jdouble x, jdouble y, jdouble z) {
    callMethod(mc->getPlayer(), mdSetPosition, x, y, z);
}

jobject EntityPlayerSP::getEntityPlayerSP() {
    return mc->getPlayer();
}
