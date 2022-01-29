#include "Minecraft.h"
#include "EntityPlayerSP.h"
#include "WorldClient.h"

Minecraft::Minecraft(UDP * udp) : AbstractClass::AbstractClass(udp, "Minecraft") {
	smdGetMinecraft = getMethodID("getMinecraft");
	fdPlayer = getFieldID("player");
	fdWorld = getFieldID("world");
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

EntityPlayerSP * Minecraft::getPlayerContainer() {
	if (!playerContainer)
		playerContainer = new EntityPlayerSP(udp, this);
	return playerContainer;
}

WorldClient * Minecraft::getWorldContainer() {
	if (!worldContainer)
		worldContainer = new WorldClient(udp, this);
	return worldContainer;
}