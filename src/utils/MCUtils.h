//
// Created by somepineaple on 2/11/22.
//

#ifndef PHANTOM_MCUTILS_H
#define PHANTOM_MCUTILS_H


#include "../mapping/impl/net/minecraft/client/Minecraft.h"
#include "../mapping/impl/net/minecraft/entity/player/EntityPlayer.h"

namespace MCUtils {
    bool sameTeam(Minecraft *mc, EntityPlayer *player);
}


#endif //PHANTOM_MCUTILS_H
