/*  COMP.CS.100 Project 2: GAME STATISTICS
 * ===============================
 * EXAMPLE SOLUTION
 * ===============================
 *
 *  Acts as a game statistics with n commands:
 * ALL_GAMES - Prints all known game names
 * GAME <game name> - Prints all players playing the given game
 * ALL_PLAYERS - Prints all known player names
 * PLAYER <player name> - Prints all games the given player plays
 * ADD_GAME <game name> - Adds a new game
 * ADD_PLAYER <game name> <player name> <score> - Adds a new player with the
 * given score for the given game, or updates the player's score if the player
 * already playes the game
 * REMOVE_PLAYER <player name> - Removes the player from all games
 *
 *  The data file's lines should be in format game_name;player_name;score
 * Otherwise the program execution terminates instantly (but still gracefully).
 *
 * */
#include "game_statistics.hh"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using std::cout;
using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::cin;
using std::getline;
using std::map;

const string PROMPT = "games> ";
const string INVALID_INPUT_ERROR = "Error: Invalid input.";

// Casual split func, if delim char is between "'s, ignores it.
std::vector<std::string> split( const std::string& str, char delim = ';' )
{
    std::vector<std::string> result = {""};
    bool inside_quatation = false;
    for ( auto current_char : str )
    {
        if ( current_char == '"' )
        {
            inside_quatation = not inside_quatation;
        }
        else if ( current_char == delim and not inside_quatation )
        {
            result.push_back("");
        }
        else
        {
            result.back().push_back(current_char);
        }
    }
    if ( result.back() == "" )
    {
        result.pop_back();
    }
    return result;
}

int main() {
    // object that handles all the information of the players games and scores
    Game_statistics stats_object = Game_statistics();

    // user interface loop
    while (true) {

        cout << PROMPT;
        string input = "";
        getline(cin, input );

        // parse command out of vector so that only parameters are left in vector
        vector<string> arguments = split(input);
        string command = arguments.at(0);
        arguments.erase(arguments.begin());

        if (command == "ALL_GAMES") {

        }

        else if (command == "GAME") {

        }

        else if (command == "ALL_PLAYERS") {

        }

        else if (command == "PLAYER") {

        }

        else if (command == "ADD_GAME")
        {
            // requires one parameter: name of the game
            if (arguments.size() != 1) {
                cout << INVALID_INPUT_ERROR << endl;
            }

            stats_object.add_game(arguments.at(0));
        }

        else if (command == "ADD_PLAYER")
        {
            //requires 3 parameters: game player score
            if (arguments.size() != 3) {
                cout << INVALID_INPUT_ERROR << endl;
            }

            int score = stoi(arguments.at(2));
            stats_object.add_player(arguments.at(0), arguments.at(1),
                                    score);
        }

        else if (command == "REMOVE") {

        }

        else if (command == "QUIT") {
             return EXIT_SUCCESS;
        }

        else {
            cout << INVALID_INPUT_ERROR << endl;
        }
    }
}
