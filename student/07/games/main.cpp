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

// Converts the given numeric string to the corresponding integer
// (by calling stoi).
// If the given string is not numeric, returns -1.
int stoi_with_check(const string& str)
{
    bool is_numeric = true;
    for(unsigned int i = 0; i < str.length(); ++i){
        if(not isdigit(str.at(i))){
            is_numeric = false;
            break;
        }
    }
    if(is_numeric){
        return stoi(str);
    }
    else{
        return -1;
    }
}

// Opens and reads a csv file by given *file_name*
// csv file has to be formated as "game;player;score"
// error messege will be printed if there is invalid line, file cant be opened,
// or score is not numeric. return true if succeeded, false otherwise.
bool read_game_stats_from_file(const string& file_name,
                               Game_statistics& stats_object) {

    std::ifstream file_object(file_name);
    // check if there is an error opening the file
    if (!file_object) {
        cout << "Error: File could not be read." << endl;
        return false;
    }

    string line = "";
    while (getline(file_object, line)) {
        vector<string> parts = split(line);

        if (parts.size() != 3) {
            cout << "Error: Invalid format in file." << endl;
            return false;
        }
        string game = parts.at(0);
        string player = parts.at(1);
        int score = stoi_with_check(parts.at(2));

        // <stoi_with_check> reutned -1 if the value was not numeric
        if (score == -1) {
            cout << "Error: Invalid format in file." << endl;
            return false;
        }

        stats_object.add_game(game); // does nothing if the game already exists
        stats_object.add_player(game, player, score);
    }
    return true;
}

int main() {
    // object that handles all the information of the players games and scores
    Game_statistics stats_object = Game_statistics();

    // read game stats from source file
    cout << "Give a name for input file: ";
    string file_name = "";
    getline(cin, file_name);
    if (!read_game_stats_from_file(file_name, stats_object)) {
        return EXIT_FAILURE;
    }

    // user interface loop
    while (true) {

        cout << PROMPT;
        string input = "";
        getline(cin, input );

        // parse command out of vector so that only parameters are left in vector
        vector<string> arguments = split(input);
        string command = arguments.at(0);
        arguments.erase(arguments.begin());

        if (command == "ALL_GAMES")
        {
            stats_object.print_all_games();
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

            // check if score is numeric <stoi_with_check> returns -1 if not
            int score = stoi_with_check(arguments.at(2));
            if (score == -1) {
                cout << INVALID_INPUT_ERROR << endl;
            }

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
