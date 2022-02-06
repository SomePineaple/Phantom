//
// Created by somepineaple on 2/5/22.
//

#ifndef PHANTOM_AXISALIGNEDBB_H
#define PHANTOM_AXISALIGNEDBB_H


#include "../AbstractClass.h"

class AxisAlignedBB : public AbstractClass {
public:
    AxisAlignedBB(Phantom *phantom, jobject aabb);

    jobject expand(jfloat x, jfloat y, jfloat z);
    jobject addCoord(jdouble x, jdouble y, jdouble z);

    AxisAlignedBB *getExpandContainer(jfloat x, jfloat y, jfloat z);
    AxisAlignedBB *getAddCoordContainer(jdouble x, jdouble y, jdouble z);
private:
    jmethodID mdExpand;
    jmethodID mdAddCoord;

    jobject aabb;
};


#endif //PHANTOM_AXISALIGNEDBB_H
