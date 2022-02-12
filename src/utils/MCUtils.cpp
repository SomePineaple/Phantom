//
// Created by somepineaple on 2/11/22.
//

#include "MCUtils.h"

#include "../mapping/impl/net/minecraft/entity/EntityPlayerSP.h"
#include "MiscUtils.h"

bool MCUtils::sameTeam(Minecraft *mc, EntityPlayer *player) {
    std::string playerName = mc->getPlayerContainer()->getName();
    std::string otherName = player->getName();

    MiscUtils::replaceStr(playerName, "§r", "");
    MiscUtils::replaceStr(otherName, "§r", "");

    return playerName.at(1) == otherName.at(1);
}
