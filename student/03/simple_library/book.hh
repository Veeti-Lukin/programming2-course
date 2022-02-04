#ifndef BOOK_HH
#define BOOK_HH

#include "date.hh"
#include <string>

class Book {

public:
    //constructor
    Book(std::string author, std::string name);

    //prints information (author : name)
    void print() const;

    // changes attribute <on_loan> to true and loaning date to *today*
    bool loan(Date today);

    //adds another 28 days to the loan. starting from loan date.
    bool renew();

    void give_back();

private:
    std::string author_;
    std::string name_;
    bool on_loan_;
    Date loaning_date_;
    Date return_date_;
};

#endif // BOOK_HH
