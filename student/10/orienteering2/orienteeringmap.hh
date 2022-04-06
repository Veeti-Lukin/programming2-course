/*
#############################################################################
# COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures          #
# Project3: Suunnistus / Orienteering                                       #
# File: orienteeringmap                                                     #
# Description: Datastructure that represents an orienteering map and        #
#        handles information of points and routes                           #
# Notes: * This is a part of an exercise program.                           #
#        * Students aren't allowed to change the public interface!          #
#        * Modifying the private part is allowed (and required).            #
#############################################################################
*/

/*
* Program author
* Name: Veeti Lukin
* Student number: 50797635
* UserID: gtvelu
* E-Mail: veeti.lukin@tuni.fi
*
* Notes about the class and it's implementation:
*   Datastructure that represents an orienteering map and handles information
*   of points and routes.
*   This is only a header file.(check orienteeringmap.cpp for class implementation.)
*
*   Public interface offers methods to set maps size, add a point to map,
*   connect 2 points in a route, print the ma, print all routes,
*   print all points, print specific routes lenght
*   and greatest method for printing continious rise after a point from all routes.
*
*   Points are implemented as struct wich is defined in route.hh.
*   Routes are implemeted as a class wich has datastructure that points to these points
*
*   Points and routes are stored in std::maps inside instance of this class.
*/



#ifndef ORIENTEERINGMAP_HH
#define ORIENTEERINGMAP_HH

#include "route.hh"
#include <string>
#include <map>

// struct Point is defined in route.hh
/*struct Point{
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
};*/

class OrienteeringMap
{
public:
    // Constructor and destructor
    OrienteeringMap();
    ~OrienteeringMap();

    // Sets the width and height for the map.
    void set_map_size(int width, int height);

    // Adds a new point in the map, with the given name, position (x and y
    // coordinates), height and marker.
    // Goes trough only if the point with same name does not exist yet
    void add_point(std::string name, int x, int y, int height, char marker);

    // Connects two existing points such that the point 'to' will be
    // immediately after the point 'from' in the route 'route_name'.
    // The given route can be either a new or an existing one,
    // if it already exists, the connection between points will be
    // updated in the aforementioned way.
    // Returns true, if connection was successful, i.e. if both the points
    // exist, otherwise returns false.
    bool connect_route(std::string from,
                       std::string to,
                       std::string route_name);

    // Prints the map.
    void print_map() const;

    // Prints all routes' names, ordered alphabetically.
    void print_routes() const;

    // Prints all points' names and their markers on the map.
    void print_points() const;

    // Prints points belonging to the given route in the order they are
    // in the route.
    void print_route(const std::string& name) const;

    // Prints the given route's combined length,
    // the length is counted as a sum of the distances of adjacent points.
    void route_length(const std::string& name) const;

    // Finds and prints the highest rise in any of the routes after the given
    // point.
    void greatest_rise(const std::string& point_name) const;

private:
    // Add here attributes and private methods.
    // At least you need a datastructure for points or routes or for both,
    // containing Point* or Route* objects (pointers).
    // Good candidates for such structures are STL maps or vectors.

    // width of the map
    int width_;
    // height of the map
    int height_;

    // datastructure for containing all Point objects on the map.
    // name of the point as a key
    std::map<std::string, Point> points = {};

    // datastucture for containing all route object.
    // routes have pointers for their own orienteering points
    // name of the route as a key
    std::map<std::string, Route> routes = {};

    // returns corresponding marker for orienteering point at given coordinates
    // if there is no point at coordinates returns '.'
    char get_marker_for_point(int x, int y) const;
};

#endif // ORIENTEERINGMAP_HH
