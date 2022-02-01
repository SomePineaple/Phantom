#ifndef PHANTOM_WORLDCLIENT_H
#define PHANTOM_WORLDCLIENT_H

#include "JavaSet.h"
#include "../AbstractClass.h"

class Minecraft;
class WorldClient : public AbstractClass
{
public:
	WorldClient(Phantom *phantom, Minecraft * mc);

	jobject getEntityList();
	void setWorldTime(jlong time);

	JavaSet * getEntities();
private:
	jfieldID fdEntityList;
	jmethodID mdSetWorldTime;

	Minecraft * mc;
};

#endif //PHANTOM_WORLDCLIENT_H
