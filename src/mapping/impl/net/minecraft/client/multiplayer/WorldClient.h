//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#ifndef PHANTOM_WORLDCLIENT_H
#define PHANTOM_WORLDCLIENT_H

#include "../../../../../AbstractClass.h"
#include <java/util/JavaList.h>

class Minecraft;
class WorldClient : public AbstractClass {
public:
	WorldClient(Phantom *phantom, Minecraft * mc);

	jobject getEntityList();
    jobject getPlayerList();
    jobject getEntitiesWithinAABBExcludingList(jobject entity, jobject AABB);
	void setWorldTime(jlong time);

	JavaList getEntities();
    JavaList getPlayers();
    JavaList getEntitiesWithinAABBExcluding(jobject entity, jobject AABB);

    jobject getWorld();
private:
	jfieldID fdEntityList;
    jfieldID fdPlayerList;
	jmethodID mdSetWorldTime;
    jmethodID mdGetEntitiesWithinAABBExcluding;

	Minecraft * mc;
};

#endif //PHANTOM_WORLDCLIENT_H
