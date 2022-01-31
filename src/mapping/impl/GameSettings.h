//
// Created by somepineaple on 1/30/22.
//

#ifndef MC_INJECTION_GAMESETTINGS_H
#define MC_INJECTION_GAMESETTINGS_H


#include "../AbstractClass.h"
#include "KeyBinding.h"

class GameSettings : public AbstractClass {
public:
    GameSettings(Phantom *phantom, jobject gameSettings);

    jobject getKeyBindAttack();
    KeyBinding *getKeyBindAttackContainer();
private:
    jobject gameSettings;
    jfieldID keyBindAttack;

    KeyBinding *keyBindAttackContainer;
};


#endif //MC_INJECTION_GAMESETTINGS_H
