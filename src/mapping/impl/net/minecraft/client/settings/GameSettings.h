//
// Created by somepineaple on 1/30/22.
//

#ifndef PHANTOM_GAMESETTINGS_H
#define PHANTOM_GAMESETTINGS_H


#include "../../../../../AbstractClass.h"
#include "KeyBinding.h"

class GameSettings : public AbstractClass {
public:
    GameSettings(Phantom *phantom, jobject gameSettings);

    jobject getKeyBindAttack();
    KeyBinding getKeyBindAttackContainer();
    jobject getGameSettings();
private:
    jobject gameSettings;
    jfieldID keyBindAttack;
};


#endif //PHANTOM_GAMESETTINGS_H
