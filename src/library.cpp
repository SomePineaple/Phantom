#include <thread>
#include "Phantom.h"
#include "mapping/impl/JavaSystem.h"
#include "utils/JvmUtils.h"

void startClient() {
    Phantom *udp = new Phantom();

    auto *system = new JavaSystem(udp);
    system->out->println(JvmUtils::getJString(udp, "Hello, we are injected"));

    udp->runClient();
}

__attribute__((constructor)) void dllLoad() {
    std::thread clientThread(startClient);
    clientThread.detach();
}
