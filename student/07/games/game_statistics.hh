#ifndef GAME_STATISTICS_HH
#define GAME_STATISTICS_HH

#include <string>
#include <map>

class Game_statistics {
public:
    // Default constructor
    Game_statistics();

    // adds game of given *game_name* without players in the <stats> data structure
    // return true if adding was succesful, false if game already exists
    bool add_game(const std::string& game_name);

    // adds a player with given name *player* to a given *game* with *score*
    // to the <stats> data structure
    // can also be used to set players score after adding
    // return true if adding was succesful, false if game dosn't exists
    bool add_player(const std::string& game, const std::string& player,
                             int score);

private:
    /* Data structure that holds the information of the games, players and scores
     * First maps key is name of the game.
     * Inner maps key is name of the player and payload is players score.
     * Example visualization:
     *  {"Sudoku" : {"Matti" : 1, "Maarit" : 50},
     *   "Hitori" : {"Maarit" : 30, "Mikko" : 10}}
     */
    std::map<std::string, std::map<std::string, int>> stats;
};

#endif // GAME_STATISTICS_HH
