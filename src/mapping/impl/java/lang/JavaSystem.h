//
// Created by somepineaple on 1/29/22.
//

#ifndef PHANTOM_JAVASYSTEM_H
#define PHANTOM_JAVASYSTEM_H

#include "../../../AbstractClass.h"
#include <java/io/JavaPrintStream.h>

class JavaSystem : public AbstractClass {
public:
    explicit JavaSystem(Phantom *phantom);
    ~JavaSystem();
    JavaPrintStream *out;
private:
};


#endif //PHANTOM_JAVASYSTEM_H
