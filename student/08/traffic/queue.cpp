#include "queue.hh"
#include <iostream>
// Implement the member functions of Queue here

Queue::Queue(unsigned int cycle): cycle_(cycle)
{

}

Queue::~Queue()
{
    while (first_ != nullptr) {
        Vehicle* temp = first_;
        first_ = first_->next;

        delete temp;
    }
}

void Queue::enqueue(const string &reg)
{
    if (!is_green_) {
        Vehicle* new_vehicle = new Vehicle{reg, nullptr};
        if (first_ == nullptr) {
            first_ = new_vehicle;
            last_ = new_vehicle;
        }
        else {
            last_->next = new_vehicle;
            last_ = new_vehicle;

        }
    }
    else {
        std::cout << "GREEN: The vehicle "<< reg <<" need not stop to wait" << endl;
    }
}

std::string Queue::dequeue()
{
    if (is_green_) {
        if (first_ != nullptr) {
            Vehicle* temp = first_;

             first_ = first_->next;

            std::string reg = temp->reg_num;
            delete temp;

            return reg + " ";
        }
    }
    return "";
}

void Queue::switch_light()
{
    is_green_ = not is_green_;

    if (is_green_) {
        std::cout << "GREEN: ";

        if (first_ == nullptr) {
            std::cout << "No vehicles waiting in traffic lights" << endl;
            return;
        }
        std::cout << "Vehicle(s) ";
        for (unsigned int i = 1; i <= cycle_; i++) {
            std::cout<< dequeue();
        }
        std::cout << "can go on";

        is_green_ = false;

    }
    else {
        std::cout << "RED: No vehicles waiting in traffic lights";
    }
    std::cout << std::endl;
}

void Queue::reset_cycle(unsigned int cycle)
{
    max_cycle_ = cycle;
    cycle_ = cycle;
}

void Queue::print() const
{
    if (is_green_) {
       std::cout << "GREEN: ";
       if (first_ == nullptr) {
           std::cout << "No vehicles waiting in traffic lights" << endl;
       }
    }
    else {
        std::cout << "RED: ";
        if (first_ == nullptr) {
            std::cout << "No vehicles waiting in traffic lights" << endl;
        }
        else {
            std::cout << "Vehicle(s) ";
            Vehicle* current_vehicle = first_;
            while (current_vehicle != nullptr) {
                std::cout << current_vehicle->reg_num << " ";
                current_vehicle = current_vehicle->next;
            }
            std::cout << "waiting in traffic lights" << endl;;
        }
    }

}
