//
// Created by somepineaple on 5/2/22.
//

#ifndef PHANTOM_HITDELAYFIX_H
#define PHANTOM_HITDELAYFIX_H

#include "Cheat.h"

class HitDelayFix : public Cheat {
public:
    HitDelayFix();
    void run(Minecraft *mc) override;
};


#endif //PHANTOM_HITDELAYFIX_H
