#include "game_statistics.hh"
#include <iostream>
#include <string>
#include <vector>

using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::cin;
using std::getline;
using std::map;

Game_statistics::Game_statistics()
{

}

bool Game_statistics::add_game(const string& game_name) {
    // check if game already exists
    if (stats.find(game_name) != stats.end()) {
        return false;
    }

    stats.insert({game_name, {}});
    return true;
}
