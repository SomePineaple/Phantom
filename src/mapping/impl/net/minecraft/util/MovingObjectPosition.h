//
// Created by somepineaple on 2/6/22.
//

#ifndef PHANTOM_MOVINGOBJECTPOSITION_H
#define PHANTOM_MOVINGOBJECTPOSITION_H


#include "../../../../AbstractClass.h"
#include <net/minecraft/util/Vec3.h>

class MovingObjectPosition : public AbstractClass {
public:
    MovingObjectPosition(Phantom *phantom, jobject movingObjectPosition);

    jobject getHitVec();

    Vec3 getHitVecContainer();

    jobject getMovingObjectPosition();
private:
    jfieldID fdHitVec;

    jobject movingObjectPosition;
};


#endif //PHANTOM_MOVINGOBJECTPOSITION_H
