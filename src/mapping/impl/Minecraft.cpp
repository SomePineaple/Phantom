#include "Minecraft.h"
#include "EntityPlayerSP.h"
#include "WorldClient.h"

Minecraft::Minecraft(Phantom *phantom) : AbstractClass::AbstractClass(phantom, "Minecraft") {
	smdGetMinecraft = getMethodID("getMinecraft");
	fdPlayer = getFieldID("player");
	fdWorld = getFieldID("world");
    fdGameSettings = getFieldID("gameSettings");

    playerContainer = nullptr;
    worldContainer = nullptr;
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

EntityPlayerSP *Minecraft::getPlayerContainer() {
    if (getPlayer() == nullptr)
        return nullptr;

	if (!playerContainer)
		playerContainer = new EntityPlayerSP(phantom, this);
	return playerContainer;
}

WorldClient *Minecraft::getWorldContainer() {
    if (getWorld() == nullptr)
        return nullptr;

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
