#include "Reading Parameters from GPS 2.h"
#include "ReadingFromGPS.h"
#include "uart4_init.h"
struct position{
    double lat;
    double lon;
};
typedef struct position pos;
pos getPosition(){
    pos temp;
    temp.lat = readThis1();
    temp.lon = readThis2();
    return temp;
}
