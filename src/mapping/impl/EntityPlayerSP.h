#pragma once

#include "../AbstractClass.h"


class UDP;
class Minecraft;
class EntityPlayerSP : public AbstractClass
{
public:
	EntityPlayerSP(UDP * udp, Minecraft * mc);

	jdouble getPosX();
	jdouble getPosY();
	jdouble getPosZ();
	jint getId();
	const char * getName();

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

	Minecraft * mc;
};

