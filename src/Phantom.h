//
// Created by somepineaple on 1/25/22.
//

#ifndef PHANTOM_PHANTOM_H
#define PHANTOM_PHANTOM_H

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


#endif //PHANTOM_PHANTOM_H
