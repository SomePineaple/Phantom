//
// Created by somepineaple on 1/30/22.
//

#ifndef PHANTOM_AIMBOT_H
#define PHANTOM_AIMBOT_H


#include "../Phantom.h"
#include "../mapping/impl/net/minecraft/client/Minecraft.h"
#include "Cheat.h"

class AimBot : public Cheat {
public:
    AimBot(Phantom *phantom);
    void run(Minecraft *mc) override;
    void renderSettings() override;
    float range;
private:
    Phantom *phantom;
};


#endif //PHANTOM_AIMBOT_H
