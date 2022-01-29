//
// Created by somepineaple on 1/25/22.
//

#ifndef MC_INJECTION_CM_H
#define MC_INJECTION_CM_H

#include <map>
#include <string>
#include "Mem.h"

struct CM {
    const char* name;
    std::map<std::string, Mem> fields;
    std::map<std::string, Mem> methods;
    explicit CM(const char* clsName) : name(clsName) {}
};

#endif //MC_INJECTION_CM_H
