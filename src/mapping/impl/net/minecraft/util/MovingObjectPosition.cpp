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

Vec3 MovingObjectPosition::getHitVecContainer() {
    return Vec3(phantom, getHitVec());
}

jobject MovingObjectPosition::getMovingObjectPosition() {
    return movingObjectPosition;
}
