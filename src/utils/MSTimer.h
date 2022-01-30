//
// Created by somepineaple on 1/30/22.
//

#ifndef MC_INJECTION_MSTIMER_H
#define MC_INJECTION_MSTIMER_H


class MSTimer {
public:
    MSTimer();
    ~MSTimer();
    bool hasTimePassed(long time) const;
    void reset();
private:
    long lastTime;
};


#endif //MC_INJECTION_MSTIMER_H
