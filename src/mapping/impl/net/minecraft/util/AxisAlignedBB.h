//
// Created by somepineaple on 2/5/22.
//

#ifndef PHANTOM_AXISALIGNEDBB_H
#define PHANTOM_AXISALIGNEDBB_H


#include "../../../../AbstractClass.h"
#include <net/minecraft/util/MovingObjectPosition.h>

class AxisAlignedBB : public AbstractClass {
public:
    AxisAlignedBB(Phantom *phantom, jobject aabb);

    jobject expand(jdouble x, jdouble y, jdouble z);
    jobject addCoord(jdouble x, jdouble y, jdouble z);
    jobject calculateIntercept(jobject vec1, jobject vec2);
    jboolean isVecInside(jobject vec);

    AxisAlignedBB getExpandContainer(jdouble x, jdouble y, jdouble z);
    AxisAlignedBB getAddCoordContainer(jdouble x, jdouble y, jdouble z);
    MovingObjectPosition getCalculateInterceptContainer(jobject vec1, jobject vec2);

    jobject getAABB();
private:
    jmethodID mdExpand;
    jmethodID mdAddCoord;
    jmethodID mdCalculateIntercept;
    jmethodID mdIsVecInside;

    jobject aabb;
};


#endif //PHANTOM_AXISALIGNEDBB_H
