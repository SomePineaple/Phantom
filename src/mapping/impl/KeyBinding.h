//
// Created by somepineaple on 1/30/22.
//

#ifndef MC_INJECTION_KEYBINDING_H
#define MC_INJECTION_KEYBINDING_H


#include "../AbstractClass.h"

class KeyBinding : public AbstractClass {
public:
    KeyBinding(Phantom *phantom);
    void onTick(jint key);
    void setKeyBindState(jint key, jboolean state);
private:
    jmethodID mdOnTick;
    jmethodID mdSetKeyBindState;
};


#endif //MC_INJECTION_KEYBINDING_H
