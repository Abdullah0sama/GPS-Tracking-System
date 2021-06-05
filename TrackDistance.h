#include "math.h"
#include "Position"
#define     PI 3.14159265359

double deg2rad(double deg){
    return deg * (PI / 180);
}

// Calculate distance between two points
double distanceBetweenPoints(pos first, pos second){
    double radius = 6.371 * 1000000;
    double dLat = deg2rad(second.lat - first.lat);
    double dLon = deg2rad(second.lon - first.lon);
    double a = sin(dLat / 2) * sin(dLat / 2) +
                cos(deg2rad(first.lat)) * cos(deg2rad(second.lat)) *
                sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = radius * c;
    return d;
}