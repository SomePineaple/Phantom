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
    void reset(Minecraft *mc) override;
    void renderSettings() override;
private:

    Phantom *phantom;


    // Settings
    bool showHitbox;
    bool devSize;
    int scale;
    float selfWidth, selfHeight;

};

#endif //PHANTOM_HITBOX_H

