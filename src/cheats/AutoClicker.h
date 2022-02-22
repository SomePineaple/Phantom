//
// Created by somepineaple on 1/30/22.
//

#ifndef PHANTOM_AUTOCLICKER_H
#define PHANTOM_AUTOCLICKER_H

#include "../Phantom.h"
#include "Cheat.h"
#include "../utils/MSTimer.h"

class AutoClicker : public Cheat {
public:
    explicit AutoClicker();
    void run(Minecraft *mc) override;
    void renderSettings() override;
private:
    void updateValues();

    MSTimer *clickTimer;
    MSTimer *eventTimer;

    float cps;
    bool onlyInGame;

    int nextDelay;
    int eventDelay;
    int nextEventDelay;
    float dropChance;
    float spikeChance;
    bool isSpiking;
    bool isDropping;
};


#endif //PHANTOM_AUTOCLICKER_H
