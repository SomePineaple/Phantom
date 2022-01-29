//
// Created by somepineaple on 1/28/22.
//

#include "MathHelper.h"

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

double MathHelper::toDegrees(double rad) {
    return rad * 180.0 / M_PI;
}

double MathHelper::toRadians(double deg) {
    return deg * M_PI / 180.0;
}
