//
// Created by somepineaple on 1/31/22.
//

#ifndef MC_INJECTION_CHEAT_H
#define MC_INJECTION_CHEAT_H


#include "../mapping/impl/Minecraft.h"

class Cheat {
public:
    explicit Cheat(const char *name, const char *description = "");
    virtual void run(Minecraft *mc);
    virtual void renderSettings();
    const char *getName();
    const char *getDescription();

    bool enabled;
private:
    const char *name;
    const char *description;
};


#endif //MC_INJECTION_CHEAT_H
