//
// Created by somepineaple on 2/1/22.
//

#ifndef PHANTOM_HITBOX_H
#define PHANTOM_HITBOX_H


#include "Cheat.h"

class EntityPlayer;
class Hitbox : public Cheat {
public:
    explicit Hitbox(Phantom *phantom);

    void run(Minecraft *mc) override;
    void renderSettings() override;
private:

    Phantom *phantom;


    // Settings
    bool defaultSelfHitbox;
    bool phase;
    float selfWidth, selfHeight;

};

#endif //PHANTOM_HITBOX_H

