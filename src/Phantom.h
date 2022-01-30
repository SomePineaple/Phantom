//
// Created by somepineaple on 1/25/22.
//

#ifndef MC_INJECTION_PHANTOM_H
#define MC_INJECTION_PHANTOM_H

#include <jvmti.h>

class Phantom {
public:
    Phantom();

    void runClient();

    JavaVM *getJvm();
    JNIEnv *getEnv();
    void setRunning(bool p_running);
    bool isRunning() const;
private:
    bool running;
    JavaVM *jvm;
    JNIEnv *env;
};


#endif //MC_INJECTION_PHANTOM_H
