#include "Minecraft.h"
#include "WorldClient.h"

WorldClient::WorldClient(Phantom * udp, Minecraft * mc) : AbstractClass::AbstractClass(udp, "WorldClient") {
	this->mc = mc;
	fdEntityList = getFieldID("entities");
	mdSetWorldTime = getMethodID("setTime");
}

jobject WorldClient::getEntityList() {
	return getObject(mc->getWorld(), fdEntityList);
}

void WorldClient::setWorldTime(jlong time) {
	callMethod(mc->getWorld(), mdSetWorldTime, time);
}

JavaSet * WorldClient::getEntities() {
	auto * set = new JavaSet(udp, getEntityList());
	return set;
}
