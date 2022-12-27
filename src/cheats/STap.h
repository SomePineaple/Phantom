#ifndef PHANTOM_STAP_H
#define PHANTOM_STAP_H

#include "Cheat.h"

class STap : public Cheat {
public:
    explicit STap(Phantom *phantom);

    void run(Minecraft *mc) override;
    void reset(Minecraft *mc) override;

    void renderSettings() override;
private:
    Phantom *phantom;

    float engageDistance;
    float disengageDistance;

    int numIntersections;
    double dist;

    bool holding;
};

#endif // PHANTOM_STAP_H

