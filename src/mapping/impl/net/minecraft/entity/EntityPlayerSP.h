//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#ifndef PHANTOM_ENTITYPLAYERSP_H
#define PHANTOM_ENTITYPLAYERSP_H

#include "../../../../AbstractClass.h"


class Phantom;
class Minecraft;
class EntityPlayerSP : public AbstractClass {
public:
	EntityPlayerSP(Phantom *phantom, Minecraft *mc);

	jdouble getPosX();
	jdouble getPosY();
	jdouble getPosZ();

    jfloat getEyeHeight();

    jfloat getRotationYaw();
    jfloat getRotationPitch();

	jint getId();
	const char *getName();
    const char *getFormattedDisplayName();
    const char *getClickedItem();


	void setRotationYaw(jfloat yaw);
	void setRotationPitch(jfloat pitch);
	void setSprinting(jboolean sprinting);

    void setSpeed(jfloat speed);
    void setVelocity(jfloat horizontal, jfloat vertical, jint change);
    void setPosition(jfloat x, jfloat y, jfloat z);

    void setCurBlockDamageMP(jfloat damage);
    jboolean getIsHittingBlock();

    void setSelfWidth(jfloat width);
    void setSelfHeight(jfloat height);

    jobject getEntityPlayerSP();
private:
	jfieldID fdPosX;
	jfieldID fdPosY;
	jfieldID fdPosZ;
	jfieldID fdRotationYaw;
	jfieldID fdRotationPitch;
    jfieldID fdForwardSpeed, fdStrafeSpeed;
    /* jfieldID fdSpeed; */
    /* jfieldID fdGetCurrentItem; */
    /* jfieldID fdGetSlotIndex; */
    /* jfieldID fdGetEquipment; */
    /* jfieldID fdGetClickedItem; */
    jfieldID fdSelfWidth, fdSelfHeight;
    /* jfieldID fdGetCurrentPlayerItem; */
    jfieldID fdGetCurBlockDamageMP;

    jmethodID mdSetPosition;
    jmethodID mdSetVelocity;
	jmethodID mdGetId;
	jmethodID mdGetName;
	jmethodID mdSetSprinting;
    jmethodID mdGetEyeHeight;
    jmethodID mdGetDisplayName;

    jmethodID mdIChatComponentGetFmtTxt;

	Minecraft *mc;
};

#endif //PHANTOM_ENTITYPLAYERSP_H

