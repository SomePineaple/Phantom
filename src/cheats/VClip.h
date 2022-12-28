//
// Created by somepineaple on 2/1/22.
//

#ifndef PHANTOM_VCLIP_H
#define PHANTOM_VCLIP_H


#include "Cheat.h"

class EntityPlayer;
class VClip : public Cheat {
public:
    explicit VClip(Phantom *phantom);

    void run(Minecraft *mc) override;
    void reset(Minecraft *mc) override;

    void renderSettings() override;
private:

    Phantom *phantom;

    // Settings
    bool teleport;
    bool type;
    bool getPosition;

    float x, y, z;

};

#endif //PHANTOM_VCLIP_H

