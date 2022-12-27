//
// Created by somepineaple on 2/21/22.
//

#ifndef PHANTOM_REACH_H
#define PHANTOM_REACH_H


#include "Cheat.h"

class Reach : public Cheat {
public:
    explicit Reach(Phantom *phantom);

    void run(Minecraft *mc) override;
    void reset(Minecraft *mc) override;

    void renderSettings() override;
private:
    Phantom *phantom;
    float reach;
};


#endif //PHANTOM_REACH_H

