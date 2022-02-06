//
// Created by somepineaple on 2/5/22.
//

#include "AxisAlignedBB.h"

AxisAlignedBB::AxisAlignedBB(Phantom *phantom, jobject aabb) : AbstractClass(phantom, "AxisAlignedBB") {
    mdExpand = getMethodID("expand");
    mdAddCoord = getMethodID("addCoord");
    mdIsVecInside = getMethodID("isVecInside");
    mdCalculateIntercept = getMethodID("calculateIntercept");

    this->aabb = aabb;
}

jobject AxisAlignedBB::expand(jfloat x, jfloat y, jfloat z) {
    return getObject(aabb, mdExpand, x, y, z);
}

jobject AxisAlignedBB::addCoord(jdouble x, jdouble y, jdouble z) {
    return getObject(aabb, mdAddCoord, x, y, z);
}

jobject AxisAlignedBB::calculateIntercept(jobject vec1, jobject vec2) {
    return getObject(aabb, mdCalculateIntercept, vec1, vec2);
}

jboolean AxisAlignedBB::isVecInside(jobject vec) {
    return getBoolean(aabb, mdIsVecInside, vec);
}

AxisAlignedBB *AxisAlignedBB::getExpandContainer(jfloat x, jfloat y, jfloat z) {
    return new AxisAlignedBB(phantom, expand(x, y, z));
}

AxisAlignedBB *AxisAlignedBB::getAddCoordContainer(jdouble x, jdouble y, jdouble z) {
    return new AxisAlignedBB(phantom, addCoord(x, y, z));
}

MovingObjectPosition *AxisAlignedBB::getCalculateInterceptContainer(jobject vec1, jobject vec2) {
    jobject mvObjecpPos = calculateIntercept(vec1, vec2);

    if (mvObjecpPos == nullptr)
        return nullptr;

    return new MovingObjectPosition(phantom, mvObjecpPos);
}
