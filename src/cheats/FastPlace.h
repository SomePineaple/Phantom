//
// Created by somepineaple on 4/29/22.
//

#ifndef PHANTOM_FASTPLACE_H
#define PHANTOM_FASTPLACE_H

#include "Cheat.h"

class FastPlace : public Cheat {
public:
    FastPlace();

    void run(Minecraft *mc) override;
    void reset(Minecraft *mc) override;
};


#endif //PHANTOM_FASTPLACE_H

