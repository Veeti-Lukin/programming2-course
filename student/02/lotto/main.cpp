#include <iostream>

using namespace std;

int main()
{
    int total_balls = 0;
    int drawn_balls = 0;

    cout << "Enter the total number of lottery balls: ";
    cin >> total_balls;
    cout << "Enter the number of drawn balls: ";
    cin >> drawn_balls;

    if (total_balls < 0 or drawn_balls < 0) {
        cout << "The number of balls must be a positive number." << endl;
        return EXIT_FAILURE;
    }

    if (drawn_balls > total_balls) {
        cout << "The maxium number of drawn balls is the total amount of balls." << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
