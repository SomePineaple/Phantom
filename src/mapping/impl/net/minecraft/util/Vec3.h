//
// Created by somepineaple on 2/5/22.
//

#ifndef PHANTOM_VEC3_H
#define PHANTOM_VEC3_H


#include "../../../../AbstractClass.h"

class Vec3 : public AbstractClass {
public:
    Vec3(Phantom *phantom, jobject vec3);

    jobject getVec3();

    jdouble getXCoord();
    jdouble getYCoord();
    jdouble getZCoord();

    jdouble distanceTo(jobject vec);

    jobject addVector(jdouble x, jdouble y, jdouble z);
    Vec3 *addVectorContainer(jdouble x, jdouble y, jdouble z);
private:
    jfieldID fdXCoord;
    jfieldID fdYCoord;
    jfieldID fdZCoord;
    jmethodID mdAddVector;
    jmethodID mdDistanceTo;

    jobject vec3;
};


#endif //PHANTOM_VEC3_H
