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
    fdLeftClickMouse = getFieldID("leftClickMouse");

    mdGetRenderViewEntity = getMethodID("getRenderViewEntity");
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

jint Minecraft::getLeftClickMouse() {
    return getInt(getMinecraft(), fdLeftClickMouse);
}

void Minecraft::setLeftClickMouse(jint leftClickMouse) {
    setInt(getMinecraft(), fdLeftClickMouse, leftClickMouse);
}

EntityPlayerSP Minecraft::getPlayerContainer() {
	return EntityPlayerSP(phantom, this);
}

WorldClient Minecraft::getWorldContainer() {
	return WorldClient(phantom, this);
}

GameSettings Minecraft::getGameSettingsContainer() {
    return GameSettings(phantom, getGameSettings());
}

Entity Minecraft::getRenderViewEntityContainer() {
    return Entity(phantom, getRenderViewEntity());
}

Timer Minecraft::getTimerContainer() {
    return Timer(phantom, getTimer());
}

EntityRenderer Minecraft::getEntityRendererContainer() {
    return EntityRenderer(phantom, getEntityRenderer());
}

Phantom *Minecraft::getPhantom() {
    return phantom;
}
