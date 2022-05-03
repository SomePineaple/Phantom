//
// Created by somepineaple on 1/29/22.
//

#include "JavaSystem.h"

JavaSystem::JavaSystem(Phantom *phantom) : AbstractClass(phantom, "System") {
    out = new JavaPrintStream(phantom, getObject(getFieldID("out")));
}

JavaSystem::~JavaSystem() {
    delete out;
}
