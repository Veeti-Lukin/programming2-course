#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include <iostream>
#include <vector>



const unsigned int BOARD_SIDE = 5;
const unsigned char EMPTY = ' ';
const unsigned int MIN_INT_VALUE = 1;
const unsigned int MAX_INT_VALUE = 5;

class Gameboard
{
public:
    // Default constructor randomizes integer values of the squares.
    Gameboard();

    // Constructor with given square integer values.
    Gameboard(const std::vector<unsigned int>& givenValues);

    // prints the gameboard with row and column numbers to console
    void print();

    // removes one value from <squares_> matrix by chaging its value to 0
    void removeSquare(unsigned int x,unsigned int y);

    // cheks if the game is won.
    // Game is won if there are no dublicate values on row or coulmn.
    bool isWon();

    // checks if the game is lost.
    // Game is lost if any adjacent square to already removed suqare gets removed
    // or if all neighbour squares of any square get removed and it becames isolated.
    bool isLost();
private:
    /* A nested vector matrix that holds information about every square and its integer value
     * vectors size will be =BOARD_SIDE  and subvectores sizes will be =BOARD_SIDE
     * Exmaple visualization:
     * {{1,2,3,4,5},
     *  {0,0,0,0,0},
     *  {0,0,0,0,0},
     *  {0,0,0,0,0},
     *  {2,3,4,5,6},
     */
    std::vector<std::vector<unsigned int>> squares_;

    // Parses vector of integers values straight to <squares_> matrix
    void parseVectorToMatrix(std::vector<unsigned int> values);

    // Generates vector of random values in range of MIN_INT_VALUE and MAX_INT_VALUE
    // Vectors size will be area of the board (BOARD_SIDE * BOARD_SIDE)
    std::vector<unsigned int> generateRandomValues() const;
};

#endif // GAMEBOARD_HH
