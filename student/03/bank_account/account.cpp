#include "account.hh"
#include <iostream>

Account::Account(const std::string& owner, bool has_credit):
    has_credit(has_credit), iban_(""), owner_(owner)
{
    generate_iban();
}

void Account::print() const
{

}

bool Account::set_credit_limit(int amount)
{

}

bool Account::save_money(int amount)
{

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
