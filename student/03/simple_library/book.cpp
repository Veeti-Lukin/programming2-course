#include "book.hh"
#include <string>
#include <iostream>

const int LOANING_TIME = 28;

Book::Book(std::string author, std::string name):
    author_(author), name_(name), on_loan_(false)
{

}

void Book::print() const{
    std::cout << author_ << " : " << name_ << std::endl;
    if (on_loan_) {
        std::cout << "- loaned: ";
        loaning_date_.print();
        std::cout << std::endl;
        std::cout << "- to be returned";
        returning_date_.print();
        std::cout << std::endl;
    }
    else { // not on loan
        std::cout << "- available" << std::endl;
    }
}

bool Book::loan(Date today) {
    if (on_loan_) {
        std::cout << "Already loaned: cannot be loaned" << std::endl;
        return false;
    }
    on_loan_ = true;
    loaning_date_ = today;
    returning_date_ = today;
    returning_date_.advance(LOANING_TIME);
    return true;
}

bool Book::renew() {
    if (!on_loan_) {
        std::cout << "Not loaned: cannot be renewed" << std::endl;
        return false;
    }
    loaning_date_.advance(LOANING_TIME);
    return true;
}

void Book::give_back()
{

}
