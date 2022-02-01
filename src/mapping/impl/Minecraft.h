//
// Some of this code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#ifndef PHANTOM_MINECRAFT_H
#define PHANTOM_MINECRAFT_H

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
    jboolean isInGameHasFocus();

	EntityPlayerSP *getPlayerContainer();
	WorldClient *getWorldContainer();
    GameSettings *getGameSettingsContainer();
private:
	jfieldID fdPlayer;
	jfieldID fdWorld;
    jfieldID fdGameSettings;
    jfieldID fdInGameHasFocus;
	jmethodID smdGetMinecraft;

	EntityPlayerSP *playerContainer;
	WorldClient *worldContainer;
    GameSettings *gameSettingsContainer;
};

#endif //PHANTOM_MINECRAFT_H
