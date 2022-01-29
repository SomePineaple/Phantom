#pragma once

#include "JavaSet.h"
#include "../AbstractClass.h"

class Minecraft;
class WorldClient : public AbstractClass
{
public:
	WorldClient(Phantom * udp, Minecraft * mc);

	jobject getEntityList();
	void setWorldTime(jlong time);

	JavaSet * getEntities();
private:
	jfieldID fdEntityList;
	jmethodID mdSetWorldTime;

	Minecraft * mc;
};

