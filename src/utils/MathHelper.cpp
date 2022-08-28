//
// Created by somepineaple on 1/28/22.
//

#include "MathHelper.h"

#include <net/minecraft/entity/player/EntityPlayer.h>
#include <net/minecraft/entity/EntityPlayerSP.h>
#include <net/minecraft/util/AxisAlignedBB.h>
#include <cmath>

using namespace std;

double MathHelper::distance(double x, double y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

double MathHelper::distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return distance(y1 - y2, distance(x1 - x2, z1 - z2));
}

MathHelper::Vec2 MathHelper::direction(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x2 - x1;
		double dy = y2 - y1;
		double dz = z2 - z1;
		double yaw = toDegrees(atan2(dz, dx)) - 90;
		double pitch = -toDegrees(atan2(dy, distance(dx, dz)));
		return { yaw, pitch };
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

MathHelper::Vec2 MathHelper::getRotations(EntityPlayerSP *player, EntityPlayer *target) {
    double deltaX = target->getPosX() + (target->getPosX() - target->getLastTickPosX()) - player->getPosX();
    double deltaY = target->getPosY() - 3.5 + target->getEyeHeight() - player->getPosY() + player->getEyeHeight();
    double deltaZ = target->getPosZ() + (target->getPosZ() - target->getLastTickPosZ()) - player->getPosZ();

    double distance = sqrt(pow(deltaX, 2) + pow(deltaZ, 2));

    double yaw = toDegrees(-atan(deltaX / deltaZ));
    double pitch =  -toDegrees(atan(deltaY / distance));

    double mathStuffs = toDegrees(atan(deltaZ / deltaX));
    if (deltaX < 0 && deltaZ < 0)
        yaw = 90 + mathStuffs;
    else if (deltaX > 0 && deltaZ < 0)
        yaw = -90 + mathStuffs;
    return {yaw, pitch};
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

double MathHelper::intersect(AxisAlignedBB &aabb, MathHelper::Ray r) {
    double t1 = (aabb.getMinX() - r.origin.x) / r.dir.x;
    double t2 = (aabb.getMaxX() - r.origin.x) / r.dir.x;
    double t3 = (aabb.getMinY() - r.origin.y) / r.dir.y;
    double t4 = (aabb.getMaxY() - r.origin.y) / r.dir.y;
    double t5 = (aabb.getMinZ() - r.origin.z) / r.dir.z;
    double t6 = (aabb.getMaxZ() - r.origin.z) / r.dir.z;

     double tmin = max(max(min(t1, t2), min(t3, t4)), min(t5, t6));
     double tmax = min(min(max(t1, t2), max(t3, t4)), max(t5, t6));

     if (tmax < 0)
        return -1;

    if (tmin > tmax)
       return -1;

    if (tmin < 0)
        return tmax;

    return tmin;
}

MathHelper::Vec3 MathHelper::normalize(const MathHelper::Vec3 &vec) {
    double length = sqrt((vec.x*vec.x) + (vec.y*vec.y) + (vec.z*vec.z));
    return {vec.x/length, vec.y/length, vec.z/length};
}
