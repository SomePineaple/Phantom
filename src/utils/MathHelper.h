//
// Created by somepineaple on 1/28/22.
//

#ifndef MC_INJECTION_MATHHELPER_H
#define MC_INJECTION_MATHHELPER_H


namespace MathHelper {
    double toDegrees(double rad);
    double toRadians(double deg);

    double distance(double x, double y);
    double distance(double x1, double y1, double z1, double x2, double y2, double z2);
    double direction(double x1, double y1, double x2, double y2);
    double *direction(double x1, double y1, double z1, double x2, double y2, double z2);
}


#endif //MC_INJECTION_MATHHELPER_H
