//
// Created by somepineaple on 1/31/22.
//

#include "MiscUtils.h"

#include <chrono>

long MiscUtils::currentTimeMS() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}
