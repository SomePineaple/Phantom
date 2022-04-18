//
// Created by somepineaple on 4/18/22.
//

#ifndef PHANTOM_KEYMANAGER_H
#define PHANTOM_KEYMANAGER_H

#include "../utils/XUtils.h"
#include "../Phantom.h"

class KeyManager {
public:
    void updateKeys(Phantom *phantom);
private:
    XUtils::DeviceState previousState{};
};


#endif //PHANTOM_KEYMANAGER_H
