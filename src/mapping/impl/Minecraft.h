#pragma once

#include "../AbstractClass.h"

class Phantom;
class EntityPlayerSP;
class WorldClient;
class Minecraft : public AbstractClass
{
public:
	Minecraft(Phantom *udp);

	jobject getMinecraft();
	jobject getPlayer();
	jobject getWorld();

	EntityPlayerSP * getPlayerContainer();
	WorldClient * getWorldContainer();
private:
	jfieldID fdPlayer;
	jfieldID fdWorld;
	jmethodID smdGetMinecraft;

	EntityPlayerSP * playerContainer;
	WorldClient * worldContainer;
};