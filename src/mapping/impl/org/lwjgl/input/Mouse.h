//
// Created by somepineaple on 1/30/22.
//

#ifndef PHANTOM_MOUSE_H
#define PHANTOM_MOUSE_H


#include "../../../../AbstractClass.h"

class Mouse : public AbstractClass {
public:
    explicit Mouse(Phantom *phantom);
    bool isButtonDown(int button);
private:
    jmethodID smdIsButtonDown;
};


#endif //PHANTOM_MOUSE_H
