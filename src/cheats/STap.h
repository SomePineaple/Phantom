#ifndef PHANTOM_STAP_H
#define PHANTOM_STAP_H

#include "Cheat.h"

class STap : public Cheat {
public:
    explicit STap(Phantom *phantom);
    void renderSettings() override;
    void run(Minecraft *mc) override;
private:
    Phantom *phantom;

    float engageDistance;
    float disengageDistance;

    int numIntersections;
    double dist;

    bool holding;
};

#endif // PHANTOM_STAP_H
