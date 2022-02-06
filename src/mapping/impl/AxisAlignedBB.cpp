//
// Created by somepineaple on 2/5/22.
//

#include "AxisAlignedBB.h"

AxisAlignedBB::AxisAlignedBB(Phantom *phantom, jobject aabb) : AbstractClass(phantom, "AxisAlignedBB") {
    mdExpand = getMethodID("expand");
    mdAddCoord = getMethodID("addCoord");

    this->aabb = aabb;
}

jobject AxisAlignedBB::expand(jfloat x, jfloat y, jfloat z) {
    return getObject(aabb, mdExpand, x, y, z);
}

jobject AxisAlignedBB::addCoord(jdouble x, jdouble y, jdouble z) {
    return getObject(aabb, mdAddCoord, x, y, z);
}

AxisAlignedBB *AxisAlignedBB::getExpandContainer(jfloat x, jfloat y, jfloat z) {
    return new AxisAlignedBB(phantom, expand(x, y, z));
}

AxisAlignedBB *AxisAlignedBB::getAddCoordContainer(jdouble x, jdouble y, jdouble z) {
    return new AxisAlignedBB(phantom, addCoord(x, y, z));
}
