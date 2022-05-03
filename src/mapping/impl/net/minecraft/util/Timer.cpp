//
// Created by somepineaple on 2/21/22.
//

#include "Timer.h"

Timer::Timer(Phantom *phantom, jobject timer) : AbstractClass(phantom, "Timer") {
    fdPartialTicks = getFieldID("partialTicks");
    this->timer = timer;
}

jfloat Timer::getPartialTicks() {
    return getFloat(timer, fdPartialTicks);
}

jobject Timer::getTimer() {
    return timer;
}
