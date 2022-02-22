//
// Some of this code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#ifndef PHANTOM_MINECRAFT_H
#define PHANTOM_MINECRAFT_H

#include "../../../../AbstractClass.h"
#include "settings/GameSettings.h"
#include "../util/Timer.h"
#include "renderer/EntityRenderer.h"

class Phantom;
class EntityPlayerSP;
class WorldClient;
class Entity;
class Minecraft : public AbstractClass {
public:
	explicit Minecraft(Phantom *phantom);

	jobject getMinecraft();
	jobject getPlayer();
	jobject getWorld();
    jobject getGameSettings();
    jobject getRenderViewEntity();
    jobject getObjectMouseOver();
    void setObjectMouseOver(jobject object);
    jobject getPointedEntity();
    void setPointedEntity(jobject object);
    jboolean isInGameHasFocus();
    jobject getTimer();
    jobject getEntityRenderer();

	EntityPlayerSP *getPlayerContainer();
	WorldClient *getWorldContainer();
    GameSettings *getGameSettingsContainer();
    Entity *getRenderViewEntityContainer();
    Timer *getTimerContainer();
    EntityRenderer *getEntityRendererContainer();
private:
	jfieldID fdPlayer;
	jfieldID fdWorld;
    jfieldID fdGameSettings;
    jfieldID fdInGameHasFocus;
    jfieldID fdObjectMouseOver;
    jfieldID fdPointedEntity;
    jfieldID fdTimer;
    jfieldID fdEntityRenderer;
	jmethodID smdGetMinecraft;
    jmethodID mdGetRenderViewEntity;

	EntityPlayerSP *playerContainer;
	WorldClient *worldContainer;
    GameSettings *gameSettingsContainer;
};

#endif //PHANTOM_MINECRAFT_H
