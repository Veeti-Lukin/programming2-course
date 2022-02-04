#include "book.hh"
#include <string>
#include <iostream>

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
    return true;
}

bool Book::renew()
{

}

void Book::give_back()
{

}
