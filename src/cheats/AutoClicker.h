//
// Created by somepineaple on 1/30/22.
//

#ifndef MC_INJECTION_AUTOCLICKER_H
#define MC_INJECTION_AUTOCLICKER_H

#include "../utils/MSTimer.h"

class AutoClicker {
public:
    explicit AutoClicker(float cps);
    void update();

    float cps;
private:
    void updateVals();

    bool isEnabled;
    MSTimer *lastClick;
    MSTimer *hold;
    double speed, holdLength, min, max;

    MSTimer *eventTimer;
    bool isSpiking, isDropping;
    int nextEventDelay;
};


#endif //MC_INJECTION_AUTOCLICKER_H
