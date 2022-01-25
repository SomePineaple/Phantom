//
// Created by somepineaple on 1/25/22.
//

#include "UDP.h"

JavaVM *UDP::getJvm() {
    return jvm;
}

JNIEnv *UDP::getEnv() {
    return env;
}
