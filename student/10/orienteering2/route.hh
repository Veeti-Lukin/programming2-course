#ifndef ROUTE_HH
#define ROUTE_HH

/*
* Program author
* Name: Veeti Lukin
* Student number: 50797635
* UserID: gtvelu
* E-Mail: veeti.lukin@tuni.fi
*
* Notes about the class and it's implementation:
*   Can be used for storing information of orienteering Route
*   This is only a header file.(check orienteeringmap.cpp for more information
*   about the program and route.cpp for class implementation.)
*
*   Public interface offers methods add a point to route, check if point is on route
*   print the points of the route, get lenght of the route and
*   method for getting continious raise after specific point on the route.
*
*   Points itself are stored in instance of OrienteeringMap class
*   wich contains instances of this class.
*   Points on this route are referenced with linked list of pointers to
*   the actual Point objects
*/

#include <string>

// models single orienteering point on orienteering map
struct Point{
    // name of the point
    std::string name_;
    // x coordinate of the point
    int x_;
    // y coordinate of the point
    int y_;
    // height where point is at
    int height;
    // character that marks the point on the map
    char marker_;
};

struct Node {
    Point* point;
    Node* next;
};

class Route
{
public:
    // constructor
    Route();
    // destructor deletes Node objects from memory
    ~Route();

    // returns bool depending if route has point with given *name*
    bool has_point(const std::string& name) const;

    // adds a point to the end of the route
    void add_point(Point* new_point);

    // prints all names of the points on this route
    void print() const;

    // calculates total lenght of the route and returns it
    float get_lenght() const;

    // calculates continuous rise, when moving from the given point along the route.
    // Continuous rise means a partial route, the starting point of which is
    // the given point and which contains no declivity, just only rise or flat.
    int get_continious_rise_from_point(const std::string point_name) const;

private:
    // pointer to first orienteering point
    Node* start_ = nullptr;
    // pointer to last orienteering point
    Node* end_ = nullptr;

    //calculates distance of two points and returns it
    float pythagoras(float x, float y) const;
};

#endif // ROUTE_HH
