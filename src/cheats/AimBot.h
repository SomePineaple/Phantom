//
// Created by somepineaple on 1/30/22.
//

#ifndef MC_INJECTION_AIMBOT_H
#define MC_INJECTION_AIMBOT_H


#include "../Phantom.h"
#include "../mapping/impl/Minecraft.h"
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


#endif //MC_INJECTION_AIMBOT_H
