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


void Gameboard::parseVectorToMatrix(const vector<unsigned int> values){
    //check header file for refrence picture of the <squares_> matrix
    //loops over the values in *values* and forms subvectors of size BOARD_SIZE
    vector<unsigned int> subVector = {};
    for (vector<unsigned int>::size_type index = 0; index < values.size(); index++) {
        subVector.push_back(values.at(index));
        // checking if should go to next "row"
        if (index % BOARD_SIDE == 0 && index != 0) {
            squares_.push_back(subVector);
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
