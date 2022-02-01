//
// Created by somepineaple on 1/31/22.
//

#ifndef PHANTOM_CHEAT_H
#define PHANTOM_CHEAT_H


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


#endif //PHANTOM_CHEAT_H
