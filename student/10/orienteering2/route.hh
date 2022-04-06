#ifndef ROUTE_HH
#define ROUTE_HH

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

    // adds a point to the end of the route
    void add_point(Point* new_point);

    // prints all names of the points on this route
    void print() const;

private:
    // pointer to first orienteering point
    Node* start_ = nullptr;
    // pointer to last orienteering point
    Node* end_ = nullptr;
};

#endif // ROUTE_HH
