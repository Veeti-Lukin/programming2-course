#include "orienteeringmap.hh"
#include <iostream>
#include <string>

const std::string ROUTE_NOT_FOUND_ERROR
                        = "Error: Route named tuntematon can't be found";


OrienteeringMap::OrienteeringMap()
{

}

OrienteeringMap::~OrienteeringMap()
{

}

void OrienteeringMap::set_map_size(int width, int height) {
    width_ = width;
    height_ = height;
}

void OrienteeringMap::add_point(std::string name, int x, int y, int height,
                                char marker) {
    if (points.find(name) == points.end()){
        points.insert({name, Point({name, x, y, height, marker})});
    }
}

bool OrienteeringMap::connect_route(std::string from, std::string to,
                                    std::string route_name) {
    // check if both point are existing points
    if (points.find(from) == points.end() || points.find(to) == points.end()) {
        return false;
    }

    // check if route already exists
    if (routes.find(route_name) == routes.end()) {
        routes.insert({route_name, Route()});
    }

    // check if route
    if (!routes.at(route_name).has_point(from)) {
        routes.at(route_name).add_point(&points.at(from));
    }

    routes.at(route_name).add_point(&points.at(to));
    return true;
}

void OrienteeringMap::print_map() const {

    // print column headers
    std::cout << " ";

    for (int i = 1; i <= width_; i++) {
        if (i < 10) {std::cout << "  " << i;}
        else {std::cout << " " << i;}
    }
    std::cout << std::endl;


    for (int y = 1; y <= height_; y++) {
        for (int x = 0; x <= width_; x++) {

            //print row header
           if (x == 0) {
               if (y < 10) {std::cout << " " << y;}
               else {std::cout << y;};
               continue;
           }
           // print actual map tile
           std::cout << "  " << get_marker_for_point(x, y);
        }
        std::cout << std::endl;
    }

}

void OrienteeringMap::print_routes() const {

    std::cout << "Routes:" << std::endl;

    for (auto &route_pair : routes) {
        std::cout << " - " << route_pair.first << std::endl;
    }
}

void OrienteeringMap::print_points() const {

    std::cout << "Points: " << std::endl;

    for (auto &point_pair : points) {
        std::cout << " - " << point_pair.second.name_ << " : "
                  <<  point_pair.second.marker_ << std::endl;
    }
}

void OrienteeringMap::print_route(const std::string &name) const {

    // check if route exists
    if (routes.find(name) == routes.end()) {
        std::cout << ROUTE_NOT_FOUND_ERROR << std::endl;
        return;
    }

    routes.at(name).print();
}

void OrienteeringMap::route_length(const std::string &name) const
{

}

void OrienteeringMap::greatest_rise(const std::string &point_name) const
{

}

char OrienteeringMap::get_marker_for_point(int x, int y) const {

    for (auto &point_pair : points) {
        if (point_pair.second.x_ == x && point_pair.second.y_ == y) {
            return point_pair.second.marker_;
        }
    }

    return '.';
}
