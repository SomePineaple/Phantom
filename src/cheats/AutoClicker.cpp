//
// Created by somepineaple on 1/30/22.
//

#include "AutoClicker.h"
#include "../utils/MathHelper.h"

AutoClicker::AutoClicker(Phantom *phantom) {
    cps = 12;

    mouse = new Mouse(phantom);

    enabled = false;
    holding = false;
    lastClick = new MSTimer();
    hold = new MSTimer();
    eventTimer = new MSTimer();
    updateVals();
}

void AutoClicker::run(Minecraft *mc) {
    if (!enabled)
        return;

    KeyBinding *keyBindAttack = mc->getGameSettingsContainer()->getKeyBindAttackContainer();

    if (mouse->isButtonDown(0)) {
        int keyCode = keyBindAttack->getKeyCode();

        if (lastClick->hasTimePassed((long)(speed * 1000.0)) && !holding) {
            lastClick->reset();
            if (hold->getTimePassed() > lastClick->getTimePassed())
                hold->reset();
            keyBindAttack->setKeyBindState(keyCode, true);
            keyBindAttack->onTick(keyCode);
            updateVals();
            holding = true;
        } else if (hold->hasTimePassed((long)(holdLength * 1000.0))) {
            keyBindAttack->setKeyBindState(keyCode, false);
            updateVals();
            holding = false;
        }
    }
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
    holdLength = speed / MathHelper::randDouble(min, max);
}
