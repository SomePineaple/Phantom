#include <thread>
#include "Phantom.h"
#include "mapping/impl/JavaSystem.h"
#include "utils/JvmUtils.h"

void startClient() {
    auto *phantom = new Phantom();

    auto *system = new JavaSystem(phantom);
    system->out->println(JvmUtils::getJString(phantom, "Phantom: Injected"));

    phantom->runClient();
}

__attribute__((constructor)) void dllLoad() {
    std::thread clientThread(startClient);
    clientThread.detach();
}
