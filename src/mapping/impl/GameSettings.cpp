//
// Created by somepineaple on 1/30/22.
//

#include "GameSettings.h"

GameSettings::GameSettings(Phantom *phantom, jobject gameSettings) : AbstractClass(phantom, "GameSettings") {
    this->gameSettings = gameSettings;
    keyBindAttack = getFieldID("keyBindAttack");
    keyBindAttackContainer = nullptr;
}

jobject GameSettings::getKeyBindAttack() {
    return getObject(gameSettings, keyBindAttack);
}

KeyBinding *GameSettings::getKeyBindAttackContainer() {
    if (getKeyBindAttack() == nullptr)
        return nullptr;
    if (keyBindAttackContainer == nullptr)
        keyBindAttackContainer = new KeyBinding(phantom, getKeyBindAttack());
    return keyBindAttackContainer;
}
