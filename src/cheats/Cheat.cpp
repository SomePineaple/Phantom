//
// Created by somepineaple on 1/31/22.
//

#include "Cheat.h"

Cheat::Cheat(const char *name) {
    this->name = name;
    this->enabled = false;
}

void Cheat::run(Minecraft *mc) {}

void Cheat::renderSettings() {}

const char *Cheat::getName() {
    return name;
}
