//
// Created by somepineaple on 1/31/22.
//

#include "Cheat.h"

Cheat::Cheat(const char *name, const char *description) {
    this->name = name;
    this->enabled = false;
    this->description = description;
    this->bind = -1;
    this->binding = false;
}

void Cheat::run(Minecraft *mc) {}
void Cheat::reset(Minecraft *mc) {}

void Cheat::renderSettings() {}

const char *Cheat::getName() {
    return name;
}

const char *Cheat::getDescription() {
    return description;
}
