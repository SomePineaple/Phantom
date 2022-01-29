#include "Minecraft.h"
#include "Entity.h"

Entity::Entity(Phantom * udp, Minecraft * mc, jobject entity) : AbstractClass::AbstractClass(udp, "Entity")
{
	this->mc = mc;
	this->entity = entity;

	//Get all the field and method IDs for Entity that we want (mappings are for 1.12)
	fdPosX = getFieldID("x");
	fdPosY = getFieldID("y");
	fdPosZ = getFieldID("z");
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

const char * Entity::getName() {
	//Needs to get the name as a jstring, then convert that to something usable
	auto str = (jstring)getObject(entity, mdGetName);
    jboolean notTrue = false;
	return udp->getEnv()->GetStringUTFChars(str, &notTrue);
}
