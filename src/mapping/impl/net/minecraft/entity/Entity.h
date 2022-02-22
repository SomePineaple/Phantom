//
// Some of this code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#ifndef PHANTOM_ENTITY_H
#define PHANTOM_ENTITY_H

#include "../../../java/util/JavaSet.h"
#include "../../../../AbstractClass.h"
#include "../util/Vec3.h"
#include "../util/AxisAlignedBB.h"

class Minecraft;
class Entity : public AbstractClass {
public:
	Entity(Phantom *phantom, Minecraft * mc, jobject entity);

	jdouble getPosX();
	jdouble getPosY();
	jdouble getPosZ();

    jdouble getLastTickPosX();
    jfloat getEyeHeight();
    jdouble getLastTickPosZ();

    jfloat getCollisionBorderSize();

    jobject rayTrace(jdouble distance, jfloat partialTicks);
    jobject getPositionEyes(jfloat partialTicks);
    jobject getLook(jfloat partialTicks);
    jobject getEntityBoundingBox();
    jobject getRidingEntity();
    jboolean canRiderInteract();

    Vec3 *getPositionEyesContainer(jfloat partialTicks);
    Vec3 *getLookContainer(jfloat partialTicks);

    AxisAlignedBB *getEntityBoundingBoxContainer();

    Entity *getRidingEntityContainer();

	jint getId();
	const char *getName();
private:
	jfieldID fdPosX;
    jfieldID fdLastTickPosX;
	jfieldID fdPosY;
	jfieldID fdPosZ;
    jfieldID fdLastTickPosZ;
    jfieldID fdRidingEntity;
    jmethodID mdGetEyeHeight;
	jmethodID mdGetId;
	jmethodID mdGetName;
    jmethodID mdRayTrace;
    jmethodID mdGetPositionEyes;
    jmethodID mdGetLook;
    jmethodID mdGetEntityBoundingBox;
    jmethodID mdGetCollisionBorderSize;
    jmethodID mdCanRiderInteract;

	Minecraft *mc;
	jobject entity;
};

#endif //PHANTOM_ENTITY_H
