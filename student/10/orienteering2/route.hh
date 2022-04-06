#ifndef ROUTE_HH
#define ROUTE_HH

#include "point.hh"

struct Node {
    Point* point;
    Node* next;
};

class Route
{
public:
    // constructor
    Route();
    // destructor
    ~Route();

    // adds a point to the end of the route
    void add_point(Point* new_point);

private:
    // pointer to first orienteering point
    Node* start_ = nullptr;
    // pointer to last orienteering point
    Node* end_ = nullptr;
};

#endif // ROUTE_HH
