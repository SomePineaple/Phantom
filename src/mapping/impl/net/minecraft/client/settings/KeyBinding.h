//
// Created by somepineaple on 1/30/22.
//

#ifndef PHANTOM_KEYBINDING_H
#define PHANTOM_KEYBINDING_H


#include "../../../../../AbstractClass.h"

class KeyBinding : public AbstractClass {
public:
    explicit KeyBinding(Phantom *phantom, jobject keyBinding = nullptr);
    void onTick(jint key);
    void setKeyBindState(jint key, jboolean state);

    int getKeyCode();

    jobject getKeyBinding();
private:
    jobject keyBinding;

    jmethodID mdOnTick;
    jmethodID mdSetKeyBindState;
    jmethodID mdGetKeyCode;
};


#endif //PHANTOM_KEYBINDING_H
