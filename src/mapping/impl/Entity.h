#pragma once

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

