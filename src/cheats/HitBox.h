//
// Created by somepineaple on 2/1/22.
//

#ifndef PHANTOM_HITBOX_H
#define PHANTOM_HITBOX_H


#include "Cheat.h"

class EntityPlayer;
class HitBox : public Cheat {
public:
    explicit HitBox(Phantom *phantom);

    void run(Minecraft *mc) override;
    void reset(Minecraft *mc) override;

    void renderSettings() override;
private:

    Phantom *phantom;


    bool canBeResetTemporaryVariableThatsWhyTheNameIsSoLongSoIWantToFixThisMore;

    // Settings
    bool showHitbox;
    bool reload;
    bool devSize;
    int scale;
    float selfWidth, selfHeight;
    float oldSelfWidth, oldSelfHeight;

};

#endif //PHANTOM_HITBOX_H

