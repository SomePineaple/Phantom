//
// Created by somepineaple on 2/1/22.
//

#ifndef PHANTOM_MSTIMER_H
#define PHANTOM_MSTIMER_H


class MSTimer {
public:
    MSTimer();
    ~MSTimer();

    bool hasTimePassed(long time) const;

    void reset();

private:
    long lastTime;
};


#endif //PHANTOM_MSTIMER_H
