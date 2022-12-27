//
// Created by somepineaple on 5/2/22.
//

#include "HitDelayFix.h"

HitDelayFix::HitDelayFix() : Cheat("1.7 Hit Delay", "Fixes 1.8 being wierd") {}

void HitDelayFix::run(Minecraft *mc) {
    mc->setLeftClickMouse(0);
}

void HitDelayFix::reset(Minecraft *mc) {}
