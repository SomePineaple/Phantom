//
// Created by somepineaple on 4/29/22.
//

#include "FastPlace.h"

FastPlace::FastPlace() : Cheat("Fast Place", "Places blocks faster & stuff") {}

void FastPlace::run(Minecraft *mc) {
    mc->setRightClickDelayTimer(0);
}
