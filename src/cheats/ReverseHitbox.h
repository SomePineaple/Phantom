//
// Created by somepineaple on 2/1/22.
//

#ifndef PHANTOM_REVERSEHITBOX_H
#define PHANTOM_REVERSEHITBOX_H


#include "Cheat.h"

class EntityPlayer;
class ReverseHitbox : public Cheat {
public:
    explicit ReverseHitbox(Phantom *phantom);

    void run(Minecraft *mc) override;
    void renderSettings() override;
private:

    Phantom *phantom;


    // Settings
    bool defaultHitbox;
    float width, height;

};

#endif //PHANTOM_REVERSEHITBOX_H

