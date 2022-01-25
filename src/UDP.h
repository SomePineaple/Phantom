//
// Created by somepineaple on 1/25/22.
//

#ifndef MC_INJECTION_UDP_H
#define MC_INJECTION_UDP_H

#include "jvmti.h"

class UDP {
public:
    UDP();
    JavaVM * getJvm();
    JNIEnv * getEnv();
private:
    JavaVM * jvm;
    JNIEnv * env;
};


#endif //MC_INJECTION_UDP_H
