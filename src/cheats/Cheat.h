//
// Created by somepineaple on 1/31/22.
//

#ifndef MC_INJECTION_CHEAT_H
#define MC_INJECTION_CHEAT_H


#include "../mapping/impl/Minecraft.h"

class Cheat {
public:
    explicit Cheat(const char *name);
    virtual void run(Minecraft *mc);
    virtual void renderSettings();
    const char *getName();

    bool enabled;
private:
    const char *name;
};


#endif //MC_INJECTION_CHEAT_H
