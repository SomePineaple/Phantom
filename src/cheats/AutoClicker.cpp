//
// Created by somepineaple on 1/30/22.
//

#include "AutoClicker.h"
#include "../utils/MathHelper.h"

AutoClicker::AutoClicker(Phantom *phantom, float cps) {
    this->cps = cps;

    mouse = new Mouse(phantom);

    isEnabled = false;
    lastClick = new MSTimer();
    hold = new MSTimer();
    eventTimer = new MSTimer();
    updateVals();
}

void AutoClicker::update() {

}

void AutoClicker::updateVals() {
    min = cps - 2;
    max = cps + 2;

    if (eventTimer->hasTimePassed(nextEventDelay)) {
        nextEventDelay = (int)(3000.0 * MathHelper::randFloat(0.8, 1.2));
        eventTimer->reset();

        int random = MathHelper::randInt(0, 100);
        if (random < 25) {
            isSpiking = true;
            isDropping = false;
        } else if (random < 75) {
            isSpiking = false;
            isDropping = false;
        } else {
            isSpiking = false;
            isDropping = true;
        }
    }

    if (isSpiking) {
        max = cps + 4;
        min = cps;
    } else if (isDropping) {
        max = cps;
        min = cps - 4;
    }

    speed = 1.0 / MathHelper::randDouble(min, max);
    holdLength = 1.0 / MathHelper::randDouble(min, max);
}
