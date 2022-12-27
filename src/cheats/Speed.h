//
// Created by somepineaple on 2/1/22.
//

#ifndef PHANTOM_SPEED_H
#define PHANTOM_SPEED_H


#include "Cheat.h"

class EntityPlayer;
class Speed : public Cheat {
public:
    explicit Speed(Phantom *phantom);

    void run(Minecraft *mc) override;
    void reset(Minecraft *mc) override;

    void renderSettings() override;
private:

    Phantom *phantom;


    // Settings
    float speed;

};

#endif //PHANTOM_SPEED_H

