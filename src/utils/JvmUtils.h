//
// Created by somepineaple on 1/29/22.
//

#ifndef PHANTOM_JVMUTILS_H
#define PHANTOM_JVMUTILS_H


#include <jvmti.h>
#include "../Phantom.h"

namespace JvmUtils {
    jstring getJString(Phantom *phantom, const char *str);
    void checkJavaErrors(Phantom *phantom);
}


#endif //PHANTOM_JVMUTILS_H
