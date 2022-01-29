//
// Created by somepineaple on 1/29/22.
//

#ifndef MC_INJECTION_JAVASYSTEM_H
#define MC_INJECTION_JAVASYSTEM_H

#include "../AbstractClass.h"
#include "JavaPrintStream.h"

class JavaSystem : public AbstractClass {
public:
    JavaSystem(UDP *udp);
    JavaPrintStream *out;
private:
};


#endif //MC_INJECTION_JAVASYSTEM_H
