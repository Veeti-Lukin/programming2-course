#include "account.hh"
#include <iostream>

Account::Account(const std::string& owner, bool has_credit):
    has_credit_(has_credit), credit_limit_(0), saldo_(0), iban_(""), owner_(owner)
{
    generate_iban();
}

void Account::print() const {
    // prints information about the account
    std::cout << owner_ << " : " << iban_ << " : " << saldo_ << " euros" << std::endl;
}

bool Account::set_credit_limit(int amount) {
    // sets credit limit to card account if attribute < has_credit > is set to true
    // returns true if succeed, false otherwise
    if (!has_credit_) {
        std::cout << "Cannot set credit limit: the account has no credit card" << std::endl;
        return false;
    }
    if (amount <= 0)
        return false;

    credit_limit_ = amount;
    return true;
}

bool Account::save_money(int amount) {
    // adds *amount* of money to account if parameter *amount* is positivie

    if (amount <= 0)
        return false;

    saldo_ += amount;
    return true;
}

bool Account::take_money(int amount) {
    // reduces *amount* of money from the account if *amount* is positive
    // and if account has enought in balance or credit.
    if (amount <= 0)
        return false;

    if (saldo_ < amount  && !has_credit_) {
        std::cout << "Cannot take money: balance underflow" << std::endl;
        return false;
    }
    if (has_credit_ && saldo_ + credit_limit_ < amount) {
        std::cout << "Cannot take money: credit limit overflow" << std::endl;
        return false;
    }

    saldo_ -= amount;
    std:: cout << amount << " euros taken: new balance of "
               << iban_ << " is " << saldo_ << " euros" << std::endl;
    return true;
}

bool Account::transfer_to(Account& other, int amount) {
    //trasfers money from this account to *other*
    // mehtod <take_money>> will handle all error cheking before adding money to *other*
    if (!take_money(amount)) {
        std::cout << "Transfer from " << iban_ <<  " failed" << std::endl;
        return false;
    }
    other.save_money(amount);
    return true;
}

// Setting initial value for the static attribute running_number_
int Account::running_number_ = 0;

void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}
