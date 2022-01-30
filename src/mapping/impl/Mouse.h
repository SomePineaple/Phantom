//
// Created by somepineaple on 1/30/22.
//

#ifndef MC_INJECTION_MOUSE_H
#define MC_INJECTION_MOUSE_H


#include "../AbstractClass.h"

class Mouse : public AbstractClass {
public:
    Mouse(Phantom *phantom);
    bool isButtonDown(int button);
private:
    jmethodID mdIsButtonDown;
};


#endif //MC_INJECTION_MOUSE_H
