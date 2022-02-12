//
// Created by somepineaple on 1/31/22.
//

#include "MiscUtils.h"

#include <chrono>

long MiscUtils::currentTimeMS() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void MiscUtils::replaceStr(std::string &str, const std::string &from, const std::string &to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}
