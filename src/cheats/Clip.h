//
// Created by somepineaple on 2/1/22.
//

#ifndef PHANTOM_CLIP_H
#define PHANTOM_CLIP_H


#include "Cheat.h"

class EntityPlayer;
class Clip : public Cheat {
public:
    explicit Clip(Phantom *phantom);

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

#endif //PHANTOM_CLIP_H

