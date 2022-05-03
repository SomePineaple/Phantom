//
// Created by somepineaple on 1/30/22.
//

#include "GameSettings.h"

GameSettings::GameSettings(Phantom *phantom, jobject gameSettings) : AbstractClass(phantom, "GameSettings") {
    this->gameSettings = gameSettings;
    keyBindAttack = getFieldID("keyBindAttack");
}

jobject GameSettings::getKeyBindAttack() {
    return getObject(gameSettings, keyBindAttack);
}

KeyBinding GameSettings::getKeyBindAttackContainer() {
    return KeyBinding(phantom, getKeyBindAttack());
}

jobject GameSettings::getGameSettings() {
    return gameSettings;
}
