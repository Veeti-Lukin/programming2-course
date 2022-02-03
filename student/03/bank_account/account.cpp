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
    // adds money to account if parameter *amount* is positivie

    if (amount <= 0)
        return false;

    saldo_ += amount;
    return true;
}

bool Account::take_money(int amount)
{

}

bool Account::transfer_to(Account other, int amount)
{

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
