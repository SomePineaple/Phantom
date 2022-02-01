//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#ifndef PHANTOM_ENTITY_H
#define PHANTOM_ENTITY_H

#include "JavaSet.h"
#include "../AbstractClass.h"

class Minecraft;
class Entity : public AbstractClass
{
public:
	Entity(Phantom *phantom, Minecraft * mc, jobject entity);

	jdouble getPosX();
	jdouble getPosY();
	jdouble getPosZ();

    jdouble getLastTickPosX();
    jfloat getEyeHeight();
    jdouble getLastTickPosZ();

	jint getId();
	const char * getName();
private:
	jfieldID fdPosX;
    jfieldID fdLastTickPosX;
	jfieldID fdPosY;
	jfieldID fdPosZ;
    jfieldID fdLastTickPosZ;
    jmethodID mdGetEyeHeight;
	jmethodID mdGetId;
	jmethodID mdGetName;

	Minecraft *mc;
	jobject entity;
};

#endif //PHANTOM_ENTITY_H
