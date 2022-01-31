#pragma once

#include "../AbstractClass.h"
#include "GameSettings.h"

class Phantom;
class EntityPlayerSP;
class WorldClient;
class Minecraft : public AbstractClass {
public:
	explicit Minecraft(Phantom *phantom);

	jobject getMinecraft();
	jobject getPlayer();
	jobject getWorld();
    jobject getGameSettings();

	EntityPlayerSP *getPlayerContainer();
	WorldClient *getWorldContainer();
    GameSettings *getGameSettingsContainer();
private:
	jfieldID fdPlayer;
	jfieldID fdWorld;
    jfieldID fdGameSettings;
	jmethodID smdGetMinecraft;

	EntityPlayerSP *playerContainer;
	WorldClient *worldContainer;
    GameSettings *gameSettingsContainer;
};
