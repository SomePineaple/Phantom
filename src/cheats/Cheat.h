//
// Created by somepineaple on 1/31/22.
//

#ifndef PHANTOM_CHEAT_H
#define PHANTOM_CHEAT_H

#include <net/minecraft/client/Minecraft.h>

class Cheat {
public:
    explicit Cheat(const char *name, const char *description = "");
    virtual void run(Minecraft *mc);
    virtual void renderSettings();
    const char *getName();
    const char *getDescription();

    bool enabled;
    bool binding;
    int bind;
private:
    const char *name;
    const char *description;
};


#endif //PHANTOM_CHEAT_H

