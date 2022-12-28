//
// Created by somepineaple on 2/1/22.
//

#ifndef PHANTOM_AIMASSIST_H
#define PHANTOM_AIMASSIST_H


#include "Cheat.h"

class EntityPlayer;
class AimAssist : public Cheat {
public:
    explicit AimAssist(Phantom *phantom);

    void run(Minecraft *mc) override;
    void renderSettings() override;
private:
    static bool isInFOV(EntityPlayer *entity, Minecraft *mc, float fov);

    Phantom *phantom;

    // Settings
    float range;
    float fov;
    float hSpeed;
    float vSpeed;
    bool onlyOnClick;
    bool center;
    bool dead;
    bool teams;
};


#endif //PHANTOM_AIMASSIST_H
