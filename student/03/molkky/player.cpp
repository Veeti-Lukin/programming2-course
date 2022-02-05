#include "player.hh"
#include <iostream>
#include <string>

using std::cout, std::cin, std::string;

const unsigned int WINNING_POINTS = 50;

Player::Player(std::string name):
    name_(name), points_(0) {

}

string Player::get_name() {
    return name_;
}

int Player::get_points() {
    return points_;
}

bool Player::add_points(int amount)
{

}

bool Player::has_won()
{

}
