//
// Created by somepineaple on 2/1/22.
//

#ifndef PHANTOM_VELOCITY_H
#define PHANTOM_VELOCITY_H


#include "Cheat.h"

class EntityPlayer;
class Velocity : public Cheat {
public:
    explicit Velocity(Phantom *phantom);

    void run(Minecraft *mc) override;
    void reset(Minecraft *mc) override;

    void renderSettings() override;
private:

    Phantom *phantom;

    // Settings
    float chance;
    float horizontalMotion, verticalMotion;
};

#endif //PHANTOM_VELOCITY_H

