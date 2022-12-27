//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#include <net/minecraft/client/Minecraft.h>
#include "PlayerControllerMP.h"

PlayerControllerMP::PlayerControllerMP(Phantom *phantom, Minecraft *mc) : AbstractClass::AbstractClass(phantom, "PlayerControllerMP") {
	this->mc = mc;

    /* mdGetIsHittingBlock = getMethodID("isHittingBlock"); */
    mdGetIsHittingBlock = getMethodID("getIsHittingBlock");
}

jobject PlayerControllerMP::getPlayerController() {
    return mc->getPlayerController();
}

jboolean PlayerControllerMP::getIsHittingBlock() {
    return getBoolean(mc->getPlayerController(), mdGetIsHittingBlock);
}

// set to auto
