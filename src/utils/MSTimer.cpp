//
// Created by somepineaple on 2/1/22.
//

#include "MSTimer.h"

#include "MiscUtils.h"

MSTimer::MSTimer() {
    lastTime = MiscUtils::currentTimeMS();
}

bool MSTimer::hasTimePassed(long time) const {
    return MiscUtils::currentTimeMS() - lastTime > time;
}

void MSTimer::reset() {
    lastTime = MiscUtils::currentTimeMS();
}

MSTimer::~MSTimer() = default;
