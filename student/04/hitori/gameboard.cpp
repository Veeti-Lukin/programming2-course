#include "gameboard.hh"
#include <random>

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::string;

Gameboard::Gameboard(){
    // initializes random values to squares in <squares_>
    parseVectorToMatrix(generateRandomValues());
}

Gameboard::Gameboard(const vector<unsigned int>& givenValues){
    // initializes given values to squares in <squares_>
    parseVectorToMatrix(givenValues);
}

void Gameboard::print(){
    cout << "=================" << endl;
    cout << "|   | 1 2 3 4 5 |" << endl;
    cout << "-----------------" << endl;
    for(unsigned int row = 0; row < BOARD_SIDE; ++row){
        cout << "| " << row + 1 << " | ";
        for(unsigned int column = 0; column < BOARD_SIDE; ++column)
        {
            if(squares_.at(row).at(column) == 0)
            {
                cout << EMPTY << " ";
            }
            else
            {
                cout << squares_.at(row).at(column) << " ";
            }
        }
        cout << "|" << endl;
    }
    cout << "=================" << endl;
}

void Gameboard::removeSquare(unsigned int column,unsigned int row){
    // given coordinates should be 1 more than actual indexes int <squares_> matrix
    // this is because <print> method starts printin coordinates from 1
    row -= 1;
    column -= 1;

    if ((!(row < BOARD_SIDE) || !(column < BOARD_SIDE))
            || (row < 0 || column < 0)){
        cout << "Out of board" << endl;
        return;
    }

    if (squares_.at(row).at(column) == 0){
        cout << "Already removed" << endl;
        return;
    }
    squares_.at(row).at(column) = 0;
}


void Gameboard::parseVectorToMatrix(const vector<unsigned int> values){
    //check header file for refrence picture of the <squares_> matrix
    //loops over the values in *values* and forms subvectors of size BOARD_SIZE
    vector<unsigned int> subVector = {};

    for (vector<unsigned int>::size_type index = 0; index < values.size(); index++) {
        subVector.push_back(values.at(index));
        // checking if should go to next "row"
        if ((index+1) % BOARD_SIDE == 0) {
            squares_.push_back(subVector);
            subVector.clear();
        }
    }
}

vector<unsigned int> Gameboard::generateRandomValues() const{
    int seed;
    cout << "Enter a seed value: ";
    cin >> seed;

    // initializing random number generator
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<unsigned int> distr(MIN_INT_VALUE, MAX_INT_VALUE);

    // generating integer values for whole gameboard area
    unsigned int area = BOARD_SIDE * BOARD_SIDE;
    vector<unsigned int> generatedValues = {};
    for (unsigned int i = 0; i < area; i++) {
        generatedValues.push_back(distr(generator));
    }
    return generatedValues;
}
