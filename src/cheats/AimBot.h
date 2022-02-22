//
// Created by somepineaple on 1/30/22.
//

#ifndef PHANTOM_AIMBOT_H
#define PHANTOM_AIMBOT_H

#include "Cheat.h"
#include "../Phantom.h"

class AimBot : public Cheat {
public:
    explicit AimBot(Phantom *phantom);
    void run(Minecraft *mc) override;
    void renderSettings() override;
    float range;
private:
    Phantom *phantom;
};


#endif //PHANTOM_AIMBOT_H
