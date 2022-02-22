//
// Created by somepineaple on 1/25/22.
//

#include "Phantom.h"

#include <iostream>
#include <net/minecraft/client/Minecraft.h>
#include <net/minecraft/client/multiplayer/WorldClient.h>
#include <net/minecraft/entity/EntityPlayerSP.h>

#include "ui/PhantomWindow.h"

#include "cheats/AimBot.h"
#include "cheats/AutoClicker.h"
#include "cheats/AimAssist.h"
#include "cheats/Reach.h"

Phantom::Phantom() {
    running = false;
    jvm = nullptr;
    env = nullptr;

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

    std::vector<Cheat*> cheats;
    cheats.push_back(new AimBot(this));
    cheats.push_back(new AimAssist(this));
    cheats.push_back(new AutoClicker());
    cheats.push_back(new Reach(this));

    auto *window = new PhantomWindow(700, 500, "Phantom");
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
    jvm->DetachCurrentThread();
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
