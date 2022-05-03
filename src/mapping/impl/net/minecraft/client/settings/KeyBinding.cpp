//
// Created by somepineaple on 1/30/22.
//

#include "KeyBinding.h"

KeyBinding::KeyBinding(Phantom *phantom, jobject keyBinding) : AbstractClass(phantom, "KeyBinding") {
    mdOnTick = getMethodID("onTick");
    mdSetKeyBindState = getMethodID("setKeyBindState");
    mdGetKeyCode = getMethodID("getKeyCode");
    this->keyBinding = keyBinding;
}

void KeyBinding::onTick(jint key) {
    callMethod(mdOnTick, key);
}

void KeyBinding::setKeyBindState(jint key, jboolean state) {
    callMethod(mdSetKeyBindState, key, state);
}

int KeyBinding::getKeyCode() {
    if (keyBinding == nullptr || mdGetKeyCode == nullptr)
        return 0;
    return getInt(keyBinding, mdGetKeyCode);
}

jobject KeyBinding::getKeyBinding() {
    return keyBinding;
}
