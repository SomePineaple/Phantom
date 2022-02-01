//
// Created by somepineaple on 1/29/22.
//

#include "JvmUtils.h"

jstring JvmUtils::getJString(Phantom *phantom, const char *str) {
    return phantom->getEnv()->NewStringUTF(str);
}

void JvmUtils::checkJavaErrors(Phantom *phantom) {
    if (phantom->getEnv()->ExceptionCheck()) {
        phantom->getEnv()->ExceptionDescribe();
        phantom->getEnv()->ExceptionClear();
    }
}
