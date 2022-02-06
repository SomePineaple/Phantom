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
    jobject getPositionEyes();
    jobject getLook(jfloat partialTicks);
    jobject getEntityBoundingBox();

    Vec3 *getPositionEyesContainer();
    Vec3 *getLookContainer(jfloat partialTicks);

    AxisAlignedBB *getEntityBoundingBoxContainer();

	jint getId();
	const char *getName();
private:
	jfieldID fdPosX;
    jfieldID fdLastTickPosX;
	jfieldID fdPosY;
	jfieldID fdPosZ;
    jfieldID fdLastTickPosZ;
    jmethodID mdGetEyeHeight;
	jmethodID mdGetId;
	jmethodID mdGetName;
    jmethodID mdRayTrace;
    jmethodID mdGetPositionEyes;
    jmethodID mdGetLook;
    jmethodID mdGetEntityBoundingBox;
    jmethodID mdGetCollisionBorderSize;

	Minecraft *mc;
	jobject entity;
};

#endif //PHANTOM_ENTITY_H
