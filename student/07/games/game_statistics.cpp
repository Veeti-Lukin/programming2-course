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
        cout << "Error: Already exists." << endl;
        return false;
    }

    stats.insert({game_name, {}});
    return true;
}

bool Game_statistics::add_player(const string& game, const string& player,
                                          int score) {
    // check if game exists
    if (stats.find(game) == stats.end()) {
        cout << "Error: Game could not be found." << endl;
        return false;
    }
    // add player inside the games inner map
    if (stats.at(game).find(player) == stats.at(game).end()) {
        stats.at(game).insert({player, 0});
    }
    stats.at(game).at(player) = score;
    return true;
}
