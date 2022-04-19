#include <thread>
#include "Phantom.h"

void startClient() {
    (new Phantom())->runClient();
}

__attribute__((constructor)) void dllLoad() {
    std::thread clientThread(startClient);
    clientThread.detach();
}
