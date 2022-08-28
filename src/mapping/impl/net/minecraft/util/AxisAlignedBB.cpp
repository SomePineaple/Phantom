//
// Created by somepineaple on 2/5/22.
//

#include "AxisAlignedBB.h"

AxisAlignedBB::AxisAlignedBB(Phantom *phantom, jobject aabb) : AbstractClass(phantom, "AxisAlignedBB") {
    mdExpand = getMethodID("expand");
    mdAddCoord = getMethodID("addCoord");
    mdIsVecInside = getMethodID("isVecInside");
    mdCalculateIntercept = getMethodID("calculateIntercept");

    fdMaxX = getFieldID("maxX");
    fdMaxY = getFieldID("maxY");
    fdMaxZ = getFieldID("maxZ");
    fdMinX = getFieldID("minX");
    fdMinY = getFieldID("minY");
    fdMinZ = getFieldID("minZ");

    this->aabb = aabb;
}

jobject AxisAlignedBB::expand(jdouble x, jdouble y, jdouble z) {
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

jdouble AxisAlignedBB::getMaxX() {
    return getFloat(aabb, fdMaxX);
}

jdouble AxisAlignedBB::getMaxY() {
    return getFloat(aabb, fdMaxY);
}

jdouble AxisAlignedBB::getMaxZ() {
    return getFloat(aabb, fdMaxZ);
}

jdouble AxisAlignedBB::getMinX() {
    return getFloat(aabb, fdMinX);
}

jdouble AxisAlignedBB::getMinY() {
    return getFloat(aabb, fdMinY);
}

jdouble AxisAlignedBB::getMinZ() {
    return getFloat(aabb, fdMinZ);
}

AxisAlignedBB AxisAlignedBB::getExpandContainer(jdouble x, jdouble y, jdouble z) {
    return {phantom, expand(x, y, z)};
}

AxisAlignedBB AxisAlignedBB::getAddCoordContainer(jdouble x, jdouble y, jdouble z) {
    return {phantom, addCoord(x, y, z)};
}

MovingObjectPosition AxisAlignedBB::getCalculateInterceptContainer(jobject vec1, jobject vec2) {
    return {phantom, calculateIntercept(vec1, vec2)};
}

jobject AxisAlignedBB::getAABB() {
    return aabb;
}
