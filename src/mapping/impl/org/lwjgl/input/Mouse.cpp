//
// Created by somepineaple on 1/30/22.
//

#include "Mouse.h"

Mouse::Mouse(Phantom *phantom) : AbstractClass(phantom, "Mouse") {
    smdIsButtonDown = getMethodID("isButtonDown");
}

bool Mouse::isButtonDown(int button) {
    return getBoolean(cls, smdIsButtonDown, button);
}
