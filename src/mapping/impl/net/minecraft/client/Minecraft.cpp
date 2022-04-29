//
// Some of this code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#include "Minecraft.h"

#include <net/minecraft/entity/EntityPlayerSP.h>
#include <net/minecraft/client/multiplayer/WorldClient.h>

Minecraft::Minecraft(Phantom *phantom) : AbstractClass::AbstractClass(phantom, "Minecraft") {
	smdGetMinecraft = getMethodID("getMinecraft");

    fdPlayer = getFieldID("player");
	fdWorld = getFieldID("world");
    fdObjectMouseOver = getFieldID("objectMouseOver");
    fdPointedEntity = getFieldID("pointedEntity");
    fdGameSettings = getFieldID("gameSettings");
    fdInGameHasFocus = getFieldID("inGameHasFocus");
    fdTimer = getFieldID("timer");
    fdEntityRenderer = getFieldID("entityRenderer");
    fdRightClickDelayTimer = getFieldID("rightClickDelayTimer");

    mdGetRenderViewEntity = getMethodID("getRenderViewEntity");

    playerContainer = nullptr;
    worldContainer = nullptr;
    gameSettingsContainer = nullptr;
}

jobject Minecraft::getMinecraft() {
	return getObject(smdGetMinecraft);
}

jobject Minecraft::getPlayer() {
	return getObject(getMinecraft(), fdPlayer);
}

jobject Minecraft::getWorld() {
	return getObject(getMinecraft(), fdWorld);
}

jobject Minecraft::getGameSettings() {
    return getObject(getMinecraft(), fdGameSettings);
}

jboolean Minecraft::isInGameHasFocus() {
    return getBoolean(getMinecraft(), fdInGameHasFocus);
}

jobject Minecraft::getRenderViewEntity() {
    return getObject(getMinecraft(), mdGetRenderViewEntity);
}

jobject Minecraft::getObjectMouseOver() {
    return getObject(getMinecraft(), fdObjectMouseOver);
}

void Minecraft::setObjectMouseOver(jobject object) {
    setObject(getMinecraft(), fdObjectMouseOver, object);
}

jobject Minecraft::getPointedEntity() {
    return getObject(getMinecraft(), fdPointedEntity);
}

void Minecraft::setPointedEntity(jobject object) {
    setObject(getMinecraft(), fdPointedEntity, object);
}

jobject Minecraft::getTimer() {
    return getObject(getMinecraft(), fdTimer);
}

jobject Minecraft::getEntityRenderer() {
    return getObject(getMinecraft(), fdEntityRenderer);
}

jint Minecraft::getRightClickDelayTimer() {
    return getInt(getMinecraft(), fdRightClickDelayTimer);
}

void Minecraft::setRightClickDelayTimer(jint rightClickDelayTimer) {
    setInt(getMinecraft(), fdRightClickDelayTimer, rightClickDelayTimer);
}

EntityPlayerSP *Minecraft::getPlayerContainer() {
    if (getPlayer() == nullptr) return nullptr;

	if (!playerContainer)
		playerContainer = new EntityPlayerSP(phantom, this);
	return playerContainer;
}

WorldClient *Minecraft::getWorldContainer() {
    if (getWorld() == nullptr) return nullptr;

	if (!worldContainer)
		worldContainer = new WorldClient(phantom, this);
	return worldContainer;
}

GameSettings *Minecraft::getGameSettingsContainer() {
    if (getGameSettings() == nullptr)
        return nullptr;

    if (!gameSettingsContainer)
        gameSettingsContainer = new GameSettings(phantom, getGameSettings());
    return gameSettingsContainer;
}

Entity *Minecraft::getRenderViewEntityContainer() {
    if (getRenderViewEntity() == nullptr)
        return nullptr;

    return new Entity(phantom, getRenderViewEntity());
}

Timer *Minecraft::getTimerContainer() {
    jobject timer = getTimer();
    if (timer == nullptr)
        return nullptr;
    return new Timer(phantom, timer);
}

EntityRenderer *Minecraft::getEntityRendererContainer() {
    jobject entityRenderer = getEntityRenderer();
    if (entityRenderer == nullptr)
        return nullptr;
    return new EntityRenderer(phantom, entityRenderer);
}

Phantom *Minecraft::getPhantom() {
    return phantom;
}
