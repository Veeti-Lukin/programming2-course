#include "route.hh"
#include <iostream>

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

