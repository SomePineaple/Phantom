//
// Some of this code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#ifndef PHANTOM_MINECRAFT_H
#define PHANTOM_MINECRAFT_H

#include "../../../../AbstractClass.h"
#include <net/minecraft/client/settings/GameSettings.h>
#include <net/minecraft/util/Timer.h>
#include <net/minecraft/client/renderer/EntityRenderer.h>

class Phantom;
class EntityPlayerSP;
class PlayerControllerMP;
class WorldClient;
class Entity;
class Minecraft : public AbstractClass {
public:
	explicit Minecraft(Phantom *phantom);

	jobject getMinecraft();
	jobject getPlayer();
    jobject getPlayerController();
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
    jint getRightClickDelayTimer();
    void setRightClickDelayTimer(jint rightClickDelayTimer);
    jint getLeftClickMouse();
    void setLeftClickMouse(jint leftClickMouse);

	EntityPlayerSP getPlayerContainer();
    PlayerControllerMP getPlayerControllerMPContainer();
	WorldClient getWorldContainer();
    GameSettings getGameSettingsContainer();
    Entity getRenderViewEntityContainer();
    Timer getTimerContainer();
    EntityRenderer getEntityRendererContainer();
    Phantom *getPhantom();
private:
	jfieldID fdPlayer;
    jfieldID fdPlayerController;
	jfieldID fdWorld;
    jfieldID fdGameSettings;
    jfieldID fdInGameHasFocus;
    jfieldID fdObjectMouseOver;
    jfieldID fdPointedEntity;
    jfieldID fdTimer;
    jfieldID fdEntityRenderer;
    jfieldID fdRightClickDelayTimer;
    jfieldID fdLeftClickMouse;
	jmethodID smdGetMinecraft;
    jmethodID mdGetRenderViewEntity;
};

#endif //PHANTOM_MINECRAFT_H

