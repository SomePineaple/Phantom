//
// Created by somepineaple on 2/21/22.
//

#ifndef PHANTOM_TIMER_H
#define PHANTOM_TIMER_H


#include "../../../../AbstractClass.h"

class Timer : public AbstractClass {
public:
    Timer(Phantom *phantom, jobject timer);
    jfloat getPartialTicks();

    jobject getTimer();
private:
    jfieldID fdPartialTicks;

    jobject timer;
};


#endif //PHANTOM_TIMER_H
