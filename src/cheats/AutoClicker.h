//
// Created by somepineaple on 1/30/22.
//

#ifndef MC_INJECTION_AUTOCLICKER_H
#define MC_INJECTION_AUTOCLICKER_H

#include "../utils/MSTimer.h"
#include "../Phantom.h"
#include "../mapping/impl/Mouse.h"
#include "../mapping/impl/KeyBinding.h"
#include "../mapping/impl/Minecraft.h"

class AutoClicker {
public:
    explicit AutoClicker(Phantom *phantom);
    void run(Minecraft *mc);

    bool enabled;
    float cps;
private:
    void updateVals();

    Mouse *mouse;

    MSTimer *lastClick;
    MSTimer *hold;
    double speed, holdLength, min, max;

    bool holding;

    MSTimer *eventTimer;
    bool isSpiking, isDropping;
    int nextEventDelay;
};


#endif //MC_INJECTION_AUTOCLICKER_H
