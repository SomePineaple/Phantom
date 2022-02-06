//
// Created by somepineaple on 1/30/22.
//

#include "Mouse.h"

Mouse::Mouse(Phantom *phantom) : AbstractClass(phantom, "Mouse") {
    mdIsButtonDown = getMethodID("isButtonDown");
}

bool Mouse::isButtonDown(int button) {
    return getBoolean(cls, mdIsButtonDown, button);
}
