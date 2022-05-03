//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#include <net/minecraft/client/Minecraft.h>
#include "WorldClient.h"

WorldClient::WorldClient(Phantom *phantom, Minecraft *mc) : AbstractClass::AbstractClass(phantom, "WorldClient") {
	this->mc = mc;
	fdEntityList = getFieldID("entities");
    fdPlayerList = getFieldID("players");
	mdSetWorldTime = getMethodID("setTime");
    mdGetEntitiesWithinAABBExcluding = getMethodID("getEntitiesWithinAABBExcluding");
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

jobject WorldClient::getEntitiesWithinAABBExcludingList(jobject entity, jobject AABB) {
    if (mc->getWorld() == nullptr)
        return nullptr;

    return getObject(mc->getWorld(), mdGetEntitiesWithinAABBExcluding, entity, AABB);
}

void WorldClient::setWorldTime(jlong time) {
	callMethod(mc->getWorld(), mdSetWorldTime, time);
}

JavaList WorldClient::getEntities() {
	return JavaList(phantom, getEntityList());
}

JavaList WorldClient::getPlayers() {
    return JavaList(phantom, getPlayerList());
}

JavaList WorldClient::getEntitiesWithinAABBExcluding(jobject entity, jobject AABB) {
    return JavaList(phantom, getEntitiesWithinAABBExcludingList(entity, AABB));
}

jobject WorldClient::getWorld() {
    return mc->getWorld();
}
