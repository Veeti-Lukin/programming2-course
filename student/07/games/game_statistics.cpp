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

void Game_statistics::print_all_games() {
    cout << "All games in alphabetical order:" << endl;

    for (const auto& game : stats) {
        cout << game.first << endl;
    }
}

bool Game_statistics::print_game_stats(const string& game) {
    // check if game exists
    if (stats.find(game) == stats.end()) {
        cout << "Error: Game could not be found." << endl;
        return false;
    }

    cout << "Game " << game
         << " has these scores and players, listed in ascending order:"
         << endl;

    // Insert every (player-score) pairs from <stats> inner map corresponding to *game*
    // to multimap mirror_map as (score-player)
    std::multimap<int, string> mirror_map;
    for (auto& i : stats.at(game)) {
        mirror_map.insert({ i.second, i.first });
    }

    // loop trhoug multimap and print players in ascending score order
    // player with same scores will be printed to same line seperated by ", "
    bool to_same_row = false;
    for (auto iter =  mirror_map.begin(); iter != mirror_map.end(); iter++) {
        if (to_same_row) {
            cout <<", " <<iter->second;
            to_same_row = false;
        }
        else {
            cout << iter->first << " : " << iter->second;
        }
        // if next player has the same score
        if (iter->first == std::next(iter)->first) {
            to_same_row = true;
        }
        else {
            cout << endl;
        }
    }
    return true;
}
