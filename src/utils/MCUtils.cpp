//
// Created by somepineaple on 2/11/22.
//

#include "MCUtils.h"

#include <net/minecraft/entity/EntityPlayerSP.h>
#include "MiscUtils.h"

bool MCUtils::sameTeam(Minecraft *mc, EntityPlayer *player) {
    std::string playerName = mc->getPlayerContainer().getFormattedDisplayName();
    std::string otherName = player->getFormattedDisplayName();

    MiscUtils::replaceStr(playerName, "§r", "");
    MiscUtils::replaceStr(otherName, "§r", "");

    if (playerName.size() < 3 || otherName.size() < 3)
        return false;

    return playerName.at(2) == otherName.at(2);
}
