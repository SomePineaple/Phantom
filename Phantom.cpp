//
// Created by somepineaple on 1/25/22.
//

#include "Phantom.h"

#include <thread>
#include <net/minecraft/client/Minecraft.h>
#include <net/minecraft/client/multiplayer/WorldClient.h>
#include <net/minecraft/entity/EntityPlayerSP.h>
#include <net/minecraft/client/multiplayer/PlayerControllerMP.h>

#include "ui/PhantomWindow.h"

#include "cheats/AimBot.h"
#include "cheats/AutoClicker.h"
#include "cheats/AimAssist.h"
#include "cheats/Hitbox.h"
#include "cheats/Reach.h"
#include "cheats/FastPlace.h"
#include "cheats/HitDelayFix.h"
#include "cheats/STap.h"
#include "cheats/Speed.h"
#include "cheats/VClip.h"

#include "ui/KeyManager.h"

Phantom::Phantom() {
    running = false;
    jvm = nullptr;
    env = nullptr;

    jsize count;
    if (JNI_GetCreatedJavaVMs(&jvm, 1, &count) != JNI_OK || count == 0)
        return;

    jint res = jvm->GetEnv((void **)&env, JNI_VERSION_1_6);
    if (res == JNI_EDETACHED)
        res = jvm->AttachCurrentThread((void **)&env, nullptr);
    if (res != JNI_OK)
        return;

    Mapping::setup();

    cheats.push_back(new AimBot(this));
    cheats.push_back(new AutoClicker());
    cheats.push_back(new AimAssist(this));
    cheats.push_back(new Hitbox(this));
    cheats.push_back(new Reach(this));
    cheats.push_back(new FastPlace());
    cheats.push_back(new HitDelayFix());
    cheats.push_back(new STap(this));
    cheats.push_back(new Speed(this));
    cheats.push_back(new VClip(this));
}

void Phantom::runClient() {
    running = true;

    // Get minecraft instance
    auto *mc = new Minecraft(this);

    auto *window = new PhantomWindow(700, 500, "Phantom");
    window->setup();

    auto *keyManager = new KeyManager();

    while (running) {
        // This is in the loop so that the instances are current. IE, joining a new world not trying to reference the old one.
        EntityPlayerSP player = mc->getPlayerContainer();
        WorldClient world = mc->getWorldContainer();
        // Ensure the player and world are not null (IE, check if in-game)
        if (player.getEntityPlayerSP() == nullptr || world.getWorld() == nullptr) {
            window->update(cheats, running, false);
            continue;
        }

        // I don't know exactly how much time this takes, but I think calling it in a different thread upped my FPS
        std::thread(callUpdateKeys, keyManager, this).detach();
        for (Cheat *cheat : cheats) {
            if (cheat->enabled)
                cheat->run(mc);
            else if(!cheat->enabled)
                cheat->reset(mc);
        }

        window->update(cheats, running, true);
    }

    window->destruct();
    jvm->DetachCurrentThread();

    delete mc;
    delete window;
    delete keyManager;
}

void Phantom::onKey(int key) {
    for (Cheat *cheat : cheats) {
        if (cheat->binding) {
            cheat->bind = key;
            cheat->binding = false;
            return;
        }
    }

    for (Cheat *cheat : cheats) {
        if (cheat->bind == key) {
            cheat->enabled = !cheat->enabled;
        }
    }
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
