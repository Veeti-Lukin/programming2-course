#ifndef PLAYER_HH
#define PLAYER_HH
#include <string>

class Player {
    //models a player playing Finnish game Molkky
public:
    // constructor
    Player(std::string name);

    //getter for name
    std::string get_name();

    //getter for points
    int get_points();

    //adds *amount* of points to <points_>. Negative *amount* is not allowed
    //Return bool wether operation succeeds.
    bool add_points(int amount);

    //Return bool if player has won or not
    bool has_won();

private:
    std::string name_;
    int points_;
};

#endif // PLAYER_HH
