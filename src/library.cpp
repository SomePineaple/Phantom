#include "library.h"

#include <iostream>
#include <thread>

void startClient() {

}

__attribute__((constructor)) void dllLoad() {
    std::thread clientThread(startClient);
}
