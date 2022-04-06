#include "route.hh"
#include <iostream>
#include <cmath>

Route::Route()
{
}

Route::~Route() {

    while (start_ != nullptr) {
        Node* temp = start_;
        start_ = start_->next;

        // OrienteeringMap object (wich contains this Route object) should delete
        // the actual Point object(that node structs pointer points to)
        //when OrienteeringMap objects life cycle ends
        delete temp;
    }
}

bool Route::has_point(std::string &name) {

    Node* current = start_;

    // loop trough al the points (or nodes containing points)
    while (current != nullptr) {
        if (name == current->point->name_) {
            return true;
        }
        current = current->next;
    }

    return false;
}

void Route::add_point(Point* new_point) {

    Node* new_point_node = new Node({new_point, nullptr});

    // if first point in route
    if (start_ == nullptr && end_ == nullptr) {
        start_ = new_point_node;
        end_ = new_point_node;
        return;
    }

    end_->next = new_point_node;
    end_ = new_point_node;
}

void Route::print() const {

    Node* current = start_;

    // loop trough al the points (or nodes containing points)
    while (current != nullptr) {

        if (current == start_) {
            std::cout << current->point->name_ << std::endl;

        }
        else {
            std::cout << " -> " << current->point->name_ << std::endl;
        }

       current = current->next;
    }
}

float Route::get_lenght() const{

    if(start_ == nullptr) {
        return 0;
    }

    float lenght = 0;
    Node* current = start_;

    // loop trough al the points (or nodes containing points)
    while (current->next != nullptr) {
        int delta_x = current->point->x_ - current->next->point->x_;
        int delta_y = current->point->y_ - current->next->point->y_;

        lenght += pythagoras(delta_x, delta_y);

        current = current->next;
    }

    return lenght;
}

float Route::pythagoras(float x, float y) const{

    return sqrt(pow(x, 2) + pow(y, 2));

}
