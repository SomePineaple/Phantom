//
// Created by somepineaple on 1/25/22.
//

#include "Phantom.h"

#include <iostream>
#include <unistd.h>
#include "mapping/impl/Minecraft.h"
#include "mapping/impl/JavaSet.h"
#include "mapping/impl/Entity.h"
#include "mapping/impl/WorldClient.h"
#include "mapping/impl/EntityPlayerSP.h"
#include "mapping/impl/JavaSystem.h"

#include "utils/MathHelper.h"
#include "utils/JvmUtils.h"

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

    running = true;

    // Infinite loop, very error-prone but good enough for the purpose of showing that it works.
    //
    // In this case there is no null checking, so this will crash if the world is null,
    // so inject while in-game. This will crash if you leave.
    //
    while (running) {
        // This is in the loop so that the instances are current. IE, joining a new world not trying to reference the old one.
        EntityPlayerSP *player = mc->getPlayerContainer();
        WorldClient *world = mc->getWorldContainer();
        // Ensure the player and world are not null (IE, check if in-game)
        if (player == nullptr || world == nullptr) {
            system->out->println(JvmUtils::getJString(this, "Phantom: Not in game, quitting"));
            running = false;
            continue;
        }
        // Get all the entities, calculate the closest one
        JavaSet *entities = world->getEntities();
        double dist = 6;
        Entity *closest = nullptr;
        for (int i = 0; i < entities->size(); i++) {
            auto * entity = new Entity(this, mc, entities->get(i));
            if (entity->getId() != player->getId()) {
                double newDist = MathHelper::distance(entity->getPosX(), entity->getPosY(), entity->getPosZ(), player->getPosX(), player->getPosY(), player->getPosZ());
                if (newDist < dist) {
                    dist = newDist;
                    closest = entity;
                }
            }
        }

        // If there is an entity in range, look at it
        if (closest != nullptr) {
            double * rotation = MathHelper::direction(player->getPosX(), player->getPosY(), player->getPosZ(), closest->getPosX(), closest->getPosY(), closest->getPosZ());
            player->setRotationYaw((float)rotation[0]);
            player->setRotationPitch((float)rotation[1]);
        }

        // Sleep cause I'm tired. 1000000 is 1 second, usleep uses microseconds
        usleep(1000000 / 60);
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
