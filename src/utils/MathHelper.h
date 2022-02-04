//
// Created by somepineaple on 1/28/22.
//

#ifndef PHANTOM_MATHHELPER_H
#define PHANTOM_MATHHELPER_H


class EntityPlayer;
class EntityPlayerSP;
namespace MathHelper {
    double toDegrees(double rad);
    double toRadians(double deg);

    double distance(double x, double y);
    double distance(double x1, double y1, double z1, double x2, double y2, double z2);
    double direction(double x1, double y1, double x2, double y2);
    double *direction(double x1, double y1, double z1, double x2, double y2, double z2);

    float wrapAngleTo180(float angle);
    float getAngleDiff(float a, float b);

    int randInt(int min, int max);
    float randFloat(float min, float max);
    double randDouble(double min, double max);

    float findMod(float a, float b);

    float *getRotations(EntityPlayerSP *player, EntityPlayer *target);
    int getDirection(float currentYaw, float targetYaw);
}


#endif //PHANTOM_MATHHELPER_H
