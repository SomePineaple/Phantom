//
// Created by somepineaple on 1/30/22.
//

#include "KeyBinding.h"

KeyBinding::KeyBinding(Phantom *phantom) : AbstractClass(phantom, "KeyBinding") {
    mdOnTick = getMethodID("onTick");
    mdSetKeyBindState = getMethodID("setKeyBindState");
}

void KeyBinding::onTick(jint key) {
    callMethod(mdOnTick, (jint) key);
}

void KeyBinding::setKeyBindState(jint key, jboolean state) {
    callMethod(mdSetKeyBindState, key, state);
}
