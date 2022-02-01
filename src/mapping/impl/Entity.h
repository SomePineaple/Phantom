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
	jint getId();
	const char * getName();
private:
	jfieldID fdPosX;
	jfieldID fdPosY;
	jfieldID fdPosZ;
	jmethodID mdGetId;
	jmethodID mdGetName;

	Minecraft * mc;
	jobject entity;
};

#endif //PHANTOM_ENTITY_H
