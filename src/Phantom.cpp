//
// Created by somepineaple on 1/25/22.
//

#include "Phantom.h"

#include <iostream>
#include "mapping/impl/Minecraft.h"
#include "mapping/impl/WorldClient.h"
#include "mapping/impl/EntityPlayerSP.h"
#include "mapping/impl/JavaSystem.h"

#include "utils/JvmUtils.h"
#include "ui/Window.h"

#include "cheats/AimBot.h"
#include "cheats/AutoClicker.h"

Phantom::Phantom() {
    running = false;

    jsize count;
    if (JNI_GetCreatedJavaVMs(&jvm, 1, &count) != JNI_OK || count == 0) {
		return;
	}

    jint res = jvm->GetEnv((void **)&env, JNI_VERSION_1_6);
	if (res == JNI_EDETACHED)
		res = jvm->AttachCurrentThread((void **)&env, nullptr);
	if (res != JNI_OK) {
		return;
	}

    Mapping::setup();
}

void Phantom::runClient() {
    // Get minecraft instance
    auto *mc = new Minecraft(this);

    auto *system = new JavaSystem(this);

    system->out->println(JvmUtils::getJString(this, "Phantom: Got the minecraft instance"));

    std::vector<Cheat*> cheats;
    cheats.push_back(new AimBot(this));
    cheats.push_back(new AutoClicker(this));

    auto *window = new Window(500, 400, "Phantom");
    window->setup();

    running = true;
    while (running) {
        // This is in the loop so that the instances are current. IE, joining a new world not trying to reference the old one.
        EntityPlayerSP *player = mc->getPlayerContainer();
        WorldClient *world = mc->getWorldContainer();
        // Ensure the player and world are not null (IE, check if in-game)
        if (player == nullptr || world == nullptr) {
            window->update(cheats, running, false);
            continue;
        }

        for (Cheat *cheat : cheats)
            cheat->run(mc);

        window->update(cheats, running, true);
    }

    window->destruct();
}

JavaVM *Phantom::getJvm() {
    return jvm;
}

JNIEnv *Phantom::getEnv() {
    return env;
}

void Phantom::setRunning(bool p_running) {
    this->running = p_running;
}

bool Phantom::isRunning() const {
    return running;
}
