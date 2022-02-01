//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#ifndef PHANTOM_ENTITYPLAYERSP_H
#define PHANTOM_ENTITYPLAYERSP_H

#include "../AbstractClass.h"


class Phantom;
class Minecraft;
class EntityPlayerSP : public AbstractClass {
public:
	EntityPlayerSP(Phantom *phantom, Minecraft *mc);

	jdouble getPosX();
	jdouble getPosY();
	jdouble getPosZ();
    jfloat getEyeHeight();
	jint getId();
	const char *getName();

	void setRotationYaw(jfloat yaw);
	void setRotationPitch(jfloat pitch);
	void setSprinting(jboolean sprinting);
private:
	jfieldID fdPosX;
	jfieldID fdPosY;
	jfieldID fdPosZ;
	jfieldID fdRotationYaw;
	jfieldID fdRotationPitch;
	jmethodID mdGetId;
	jmethodID mdGetName;
	jmethodID mdSetSprinting;
    jmethodID mdGetEyeHeight;

	Minecraft *mc;
};

#endif //PHANTOM_ENTITYPLAYERSP_H
