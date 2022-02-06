//
// Created by somepineaple on 2/5/22.
//

#include "Vec3.h"

Vec3::Vec3(Phantom *phantom, jobject vec3) : AbstractClass(phantom, "Vec3") {
    mdAddVector = getMethodID("addVector");

    this->vec3 = vec3;
}

jobject Vec3::addVector(jdouble x, jdouble y, jdouble z) {
    return getObject(vec3, mdAddVector, x, y, z);
}

Vec3 *Vec3::addVectorContainer(jdouble x, jdouble y, jdouble z) {
    return new Vec3(phantom, addVector(x, y, z));
}
