//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#include "Minecraft.h"
#include "EntityPlayerSP.h"

EntityPlayerSP::EntityPlayerSP(Phantom * phantom, Minecraft * mc) : AbstractClass(phantom, "PlayerSP") {
	this->mc = mc;

	//Get all the field and method IDs for EntityPlayerSP that we want (mappings are for 1.12)
	fdPosX = getFieldID("x");
	fdPosY = getFieldID("y");
	fdPosZ = getFieldID("z");
	fdRotationYaw = getFieldID("yaw");
	fdRotationPitch = getFieldID("pitch");
	mdGetId = getMethodID("getID");
	mdGetName = getMethodID("getName");
	mdSetSprinting = getMethodID("setSprint");
    mdGetEyeHeight = getMethodID("getEyeHeight");
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
