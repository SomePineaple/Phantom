//
// Created by somepineaple on 1/30/22.
//

#include "MSTimer.h"

#include <chrono>

long getCurrentTimeMillis() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

MSTimer::MSTimer() {
    lastTime = getCurrentTimeMillis();
}

bool MSTimer::hasTimePassed(long time) const {
    return getCurrentTimeMillis() - lastTime > time;
}

long MSTimer::getTimePassed() const {
    return getCurrentTimeMillis() - lastTime;
}

void MSTimer::reset() {
    lastTime = getCurrentTimeMillis();
}

MSTimer::~MSTimer() = default;
