#ifndef POINT_HH
#define POINT_HH

#include <string>

class Point
{
public:
    //constructor
    Point(std::string name, int x, int y, char marker);

private:
    // name of the point
    std::string name_;
    // x coordinate of the point
    int x_;
    // y coordinate of the point
    int y_;
    // character that marks the point on the map
    char marker_;
};

#endif // POINT_HH
