#include "orienteeringmap.hh"

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
        points.insert({name, Point(name, x, y, marker)});
    }
}

bool OrienteeringMap::connect_route(std::string from, std::string to,
                                    std::string route_name) {
}

void OrienteeringMap::print_map() const
{

}

void OrienteeringMap::print_routes() const
{

}

void OrienteeringMap::print_points() const
{

}

void OrienteeringMap::print_route(const std::string &name) const
{

}

void OrienteeringMap::route_length(const std::string &name) const
{

}

void OrienteeringMap::greatest_rise(const std::string &point_name) const
{

}
