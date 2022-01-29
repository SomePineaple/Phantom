//
// Created by somepineaple on 1/29/22.
//

#include "JvmUtils.h"

jstring JvmUtils::getJString(Phantom *phantom, const char *str) {
    return phantom->getEnv()->NewStringUTF(str);
}
