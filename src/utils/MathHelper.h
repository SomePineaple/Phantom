//
// Created by somepineaple on 1/28/22.
//

#ifndef PHANTOM_MATHHELPER_H
#define PHANTOM_MATHHELPER_H


class EntityPlayer;
class EntityPlayerSP;
class AxisAlignedBB;
namespace MathHelper {
    struct Vec2 {
        double x, y;
    };

    struct Vec3 {
        double x, y, z;
    };

    struct Ray {
        Vec3 origin, dir;
    };

    double toDegrees(double rad);
    double toRadians(double deg);

    double distance(double x, double y);
    double distance(double x1, double y1, double z1, double x2, double y2, double z2);
    double direction(double x1, double y1, double x2, double y2);
    Vec2 direction(double x1, double y1, double z1, double x2, double y2, double z2);

    float wrapAngleTo180(float angle);
    float getAngleDiff(float a, float b);

    int randInt(int min, int max);
    float randFloat(float min, float max);
    double randDouble(double min, double max);

    float findMod(float a, float b);

    Vec2 getRotations(EntityPlayerSP *player, EntityPlayer *target);
    int getDirection(float currentYaw, float targetYaw);

    double intersect(AxisAlignedBB &aabb, Ray ray);

    Vec3 normalize(const Vec3 &vec);
}


#endif //PHANTOM_MATHHELPER_H
