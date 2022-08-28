//
// Created by somepineaple on 1/30/22.
//

#include "GameSettings.h"

GameSettings::GameSettings(Phantom *phantom, jobject gameSettings) : AbstractClass(phantom, "GameSettings") {
    this->gameSettings = gameSettings;
    fdKeyBindAttack = getFieldID("keyBindAttack");
    fdKeyBindBack = getFieldID("keyBindBack");
}

jobject GameSettings::getKeyBindAttack() {
    return getObject(gameSettings, fdKeyBindAttack);
}

jobject GameSettings::getKeyBindBack() {
    return getObject(gameSettings, fdKeyBindBack);
}

KeyBinding GameSettings::getKeyBindAttackContainer() {
    return KeyBinding(phantom, getKeyBindAttack());
}

KeyBinding GameSettings::getKeyBindBackContainer() {
    return KeyBinding(phantom, getKeyBindBack());
}

jobject GameSettings::getGameSettings() {
    return gameSettings;
}
