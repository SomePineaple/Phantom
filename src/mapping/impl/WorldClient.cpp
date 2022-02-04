//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#include "Minecraft.h"
#include "WorldClient.h"

WorldClient::WorldClient(Phantom *phantom, Minecraft *mc) : AbstractClass::AbstractClass(phantom, "WorldClient") {
	this->mc = mc;
	fdEntityList = getFieldID("entities");
    fdPlayerList = getFieldID("players");
	mdSetWorldTime = getMethodID("setTime");
}

jobject WorldClient::getEntityList() {
    if (mc->getWorld() == nullptr)
        return nullptr;

	return getObject(mc->getWorld(), fdEntityList);
}

jobject WorldClient::getPlayerList() {
    if (mc->getWorld() == nullptr)
        return nullptr;

    return getObject(mc->getWorld(), fdPlayerList);
}

void WorldClient::setWorldTime(jlong time) {
	callMethod(mc->getWorld(), mdSetWorldTime, time);
}

JavaList *WorldClient::getEntities() {
	return new JavaList(phantom, getEntityList());
}

JavaList *WorldClient::getPlayers() {
    if (getPlayerList() == nullptr)
        return nullptr;

    return new JavaList(phantom, getPlayerList());
}
