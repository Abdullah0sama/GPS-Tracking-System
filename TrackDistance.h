#include "math.h"
#include "Switch.h"
#include "LCD_init.h"
#include "LED_init.h"
#include  "ReadingFromGPS.h"
#include  "stdio.h"
#define     PI 3.14159265359

double deg2rad(double deg){
    return deg * (PI / 180);
}
double converCoordFormat(double temp){
    double y = (int) temp / 100;
    double z = (temp - y * 100) / 60;
    return y + z;
}
// Calculate distance between two points
double distanceBetweenPoints(pos first, pos second){
    first.lat = converCoordFormat(first.lat);
    first.lon = converCoordFormat(first.lon);
    second.lat = converCoordFormat(second.lat);
    second.lon = converCoordFormat(second.lon);


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

// Keep tracking distance until switch is pushed 
// return total distance from moment it is called until the switch is pushed
double trackDistance(){
    double totalDistance = 0;
    pos prev = readThis();

    while(!isSwitchPushed()){

        //delay for some time 
        // delay();
        pos currentPos = readThis();
        double distance = distanceBetweenPoints(prev, currentPos);
        if(distance > 1){
            prev = currentPos;
            totalDistance += distance;
            display_LCD(totalDistance);
        }
    }
    turnOnLED();
    return totalDistance;
}