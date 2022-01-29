//
// Created by somepineaple on 1/29/22.
//

#ifndef MC_INJECTION_JVMUTILS_H
#define MC_INJECTION_JVMUTILS_H


#include "jvmti.h"
#include "../Phantom.h"

namespace JvmUtils {
    jstring getJString(Phantom *udp, const char *str);
}


#endif //MC_INJECTION_JVMUTILS_H
