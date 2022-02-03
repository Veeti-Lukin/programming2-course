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
        return_date_.print();
        std::cout << std::endl;
    }
    else { // not on loan
        std::cout << "- available" << std::endl;
    }
}

bool Book::loan(Date today)
{

}

bool Book::renew()
{

}

void Book::give_back()
{

}
