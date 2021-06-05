struct position{
    double lat;
    double lon;
};
typedef struct position pos;
pos getPosition(){
    pos temp;
    temp.lat = 1;
    temp.lon = 1;
    return temp;
}