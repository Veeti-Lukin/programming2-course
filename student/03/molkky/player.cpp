#include "player.hh"
#include <iostream>
#include <string>

using std::cout, std::cin, std::string;

const unsigned int WINNING_POINTS = 50;

// public interface methods
Player::Player(std::string name):
    name_(name), points_(0) {

}

string Player::get_name() {
    return name_;
}

int Player::get_points() {
    return points_;
}

bool Player::add_points(int amount) {
    if (amount < 0)
        return false;

    points_ += amount;
    check_for_penaltypoints();
    return true;
}

bool Player::has_won() {
    if (points_ == WINNING_POINTS)
        return true;
   // else:
    return false;
}


//private methods
void Player::check_for_penaltypoints() {
    if (points_ > WINNING_POINTS)
        points_ = 25;
}
