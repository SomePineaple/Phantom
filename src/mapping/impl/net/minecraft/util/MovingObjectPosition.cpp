//
// Created by somepineaple on 2/6/22.
//

#include "MovingObjectPosition.h"

MovingObjectPosition::MovingObjectPosition(Phantom *phantom, jobject movingObjectPosition) : AbstractClass(phantom, "MovingObjectPosition") {
    fdHitVec = getFieldID("hitVec");

    this->movingObjectPosition = movingObjectPosition;
}

jobject MovingObjectPosition::getHitVec() {
    return getObject(movingObjectPosition, fdHitVec);
}

Vec3 *MovingObjectPosition::getHitVecContainer() {
    jobject hitVec = getHitVec();

    if (hitVec == nullptr)
        return nullptr;

    return new Vec3(phantom, hitVec);
}
