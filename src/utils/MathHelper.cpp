//
// Created by somepineaple on 1/28/22.
//

#include "MathHelper.h"

#include <net/minecraft/entity/player/EntityPlayer.h>
#include <net/minecraft/entity/EntityPlayerSP.h>
#include <cmath>

double MathHelper::distance(double x, double y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

double MathHelper::distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return distance(y1 - y2, distance(x1 - x2, z1 - z2));
}

double *MathHelper::direction(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x2 - x1;
		double dy = y2 - y1;
		double dz = z2 - z1;
		double yaw = toDegrees(atan2(dz, dx)) - 90;
		double pitch = -toDegrees(atan2(dy, distance(dx, dz)));
		return new double[2] { yaw, pitch };
}

float MathHelper::wrapAngleTo180(float angle) {
    float angleWrapped = MathHelper::findMod(angle, 360);
    if (angleWrapped >= 180.0F) {
        angleWrapped -= 360.0F;
    }

    if (angleWrapped < -180.0F) {
        angleWrapped += 360.0F;
    }

    return angleWrapped;
}

float MathHelper::getAngleDiff(float a, float b) {
    float phi = findMod(std::abs(b - a), 360);
    return phi > 180 ? 360 - phi : phi;
}

double MathHelper::toDegrees(double rad) {
    return rad * 180.0 / M_PI;
}

double MathHelper::toRadians(double deg) {
    return deg * M_PI / 180.0;
}

int MathHelper::randInt(int min, int max) {
    return (min <= max) ?
           ((rand() % ((max + 1) - min)) + min) :
           ((rand() % ((min + 1) - max)) + max);
}

float MathHelper::randFloat(float min, float max) {
    float random = (float)rand() / (float)RAND_MAX;
    return min + ((max - min) * random);
}

double MathHelper::randDouble(double min, double max) {
    double random = (double)rand() / (double)RAND_MAX;
    return min + ((max - min) * random);
}

float MathHelper::findMod(float a, float b) {
    float mod;
    // Handling negative values
    if (a < 0)
        mod = -a;
    else
        mod =  a;
    if (b < 0)
        b = -b;

    // Finding mod by repeated subtraction
    while (mod >= b)
        mod = mod - b;

    // Sign of result typically depends
    // on sign of a.
    if (a < 0)
        return -mod;

    return mod;
}

float *MathHelper::getRotations(EntityPlayerSP *player, EntityPlayer *target) {
    double deltaX = target->getPosX() + (target->getPosX() - target->getLastTickPosX()) - player->getPosX();
    double deltaY = target->getPosY() - 3.5 + target->getEyeHeight() - player->getPosY() + player->getEyeHeight();
    double deltaZ = target->getPosZ() + (target->getPosZ() - target->getLastTickPosZ()) - player->getPosZ();

    double distance = sqrt(pow(deltaX, 2) + pow(deltaZ, 2));

    auto yaw = (float)toDegrees(-atan(deltaX / deltaZ));
    auto pitch = (float) -toDegrees(atan(deltaY / distance));

    double mathStuffs = toDegrees(atan(deltaZ / deltaX));
    if (deltaX < 0 && deltaZ < 0)
        yaw = (float) (90 + mathStuffs);
    else if (deltaX > 0 && deltaZ < 0)
        yaw = (float) (-90 + mathStuffs);

    auto rotations = (float *) malloc(2 * sizeof(float));
    rotations[0] = yaw;
    rotations[1] = pitch;
    return rotations;
}

int MathHelper::getDirection(float currentYaw, float targetYaw) {
    if (currentYaw >= 0) {
        if (targetYaw > currentYaw)
            return 1;
        if (-180 + currentYaw < targetYaw)
            return -1;
        else
            return 1;
    } else {
        if (targetYaw < currentYaw)
            return -1;
        if (180 + currentYaw > targetYaw)
            return 1;
        else
            return -1;
    }
}
