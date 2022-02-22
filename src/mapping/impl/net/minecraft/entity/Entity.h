//
// Some of this code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#ifndef PHANTOM_ENTITY_H
#define PHANTOM_ENTITY_H

#include "../../../../AbstractClass.h"
#include <java/util/JavaSet.h>
#include <net/minecraft/util/Vec3.h>
#include <net/minecraft/util/AxisAlignedBB.h>

class Entity : public AbstractClass {
public:
	Entity(Phantom *phantom, jobject entity);

    jobject getEntity();

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
    jboolean canBeCollidedWith();

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
    jmethodID mdCanBeCollodedWith;

	jobject entity;
};

#endif //PHANTOM_ENTITY_H
