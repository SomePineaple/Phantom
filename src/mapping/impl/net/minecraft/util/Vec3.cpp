//
// Created by somepineaple on 2/5/22.
//

#include "Vec3.h"

Vec3::Vec3(Phantom *phantom, jobject vec3) : AbstractClass(phantom, "Vec3") {
    fdXCoord = getFieldID("xCoord");
    fdYCoord = getFieldID("yCoord");
    fdZCoord = getFieldID("zCoord");

    mdAddVector = getMethodID("addVector");
    mdDistanceTo = getMethodID("distanceTo");

    this->vec3 = vec3;
}

jobject Vec3::getVec3() {
    return vec3;
}

jdouble Vec3::getXCoord() {
    return getDouble(vec3, fdXCoord);
}

jdouble Vec3::getYCoord() {
    return getDouble(vec3, fdYCoord);
}

jdouble Vec3::getZCoord() {
    return getDouble(vec3, fdZCoord);
}

jdouble Vec3::distanceTo(jobject vec) {
    return getDouble(vec3, mdDistanceTo, vec);
}

jobject Vec3::addVector(jdouble x, jdouble y, jdouble z) {
    return getObject(vec3, mdAddVector, x, y, z);
}

Vec3 Vec3::addVectorContainer(jdouble x, jdouble y, jdouble z) {
    return Vec3(phantom, addVector(x, y, z));
}
