//
// Created by somepineaple on 1/29/22.
//

#include "JvmUtils.h"

jstring JvmUtils::getJString(Phantom *udp, const char *str) {
    return udp->getEnv()->NewStringUTF(str);
}
