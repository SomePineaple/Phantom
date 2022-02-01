//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#include "Entity.h"
#include "Minecraft.h"

Entity::Entity(Phantom *phantom, Minecraft *mc, jobject entity) : AbstractClass::AbstractClass(phantom, "Entity") {
	this->mc = mc;
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

jdouble Entity::getPosX() {
	return getDouble(entity, fdPosX);
}

jdouble Entity::getPosY() {
	return getDouble(entity, fdPosY);
}

jdouble Entity::getPosZ() {
	return getDouble(entity, fdPosZ);
}

jint Entity::getId() {
	return getInt(entity, mdGetId);
}

const char *Entity::getName() {
	//Needs to get the name as a jstring, then convert that to something usable
	auto str = (jstring)getObject(entity, mdGetName);
    jboolean notTrue = false;
	return phantom->getEnv()->GetStringUTFChars(str, &notTrue);
}

jdouble Entity::getLastTickPosX() {
    return getDouble(entity, fdLastTickPosX);
}

jdouble Entity::getLastTickPosZ() {
    return getDouble(entity, fdLastTickPosZ);
}

jfloat Entity::getEyeHeight() {
    return getFloat(entity, mdGetEyeHeight);
}
