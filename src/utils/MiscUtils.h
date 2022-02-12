//
// Created by somepineaple on 1/31/22.
//

#ifndef PHANTOM_MISCUTILS_H
#define PHANTOM_MISCUTILS_H

#include <string>

namespace MiscUtils {
    long currentTimeMS();
    void replaceStr(std::string& str, const std::string& from, const std::string& to);
}

#endif //PHANTOM_MISCUTILS_H
