//
// Created by somepineaple on 2/21/22.
//

#ifndef PHANTOM_REACH_H
#define PHANTOM_REACH_H


#include "Cheat.h"

class Reach : public Cheat {
public:
    Reach();
    void renderSettings() override;
    void run(Minecraft *mc) override;
private:
    float reach;
};


#endif //PHANTOM_REACH_H
