//
// Created by somepineaple on 1/30/22.
//

#ifndef MC_INJECTION_AIMBOT_H
#define MC_INJECTION_AIMBOT_H


#include "../Phantom.h"
#include "../mapping/impl/Minecraft.h"

class AimBot {
public:
    AimBot(Phantom *phantom);
    void run(Minecraft *mc);
    bool enabled;
    float range;
private:
    Phantom *phantom;
};


#endif //MC_INJECTION_AIMBOT_H
