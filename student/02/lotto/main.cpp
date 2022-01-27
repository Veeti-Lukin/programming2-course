#include <iostream>

using namespace std;

long long int factorial(int number) {
    long int number_factorial = 1;

    if (number == 0) {
        return 1;
    }

    for (int i = number; i > 0; --i) {
        number_factorial *= i;
    }

    return number_factorial;
}

long long int all_combinations(int total, int drawn) {
    return factorial(total) / (factorial(total - drawn) * factorial(drawn));
}

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
        return EXIT_SUCCESS;
    }

    if (drawn_balls > total_balls) {
        cout << "The maximum number of drawn balls is the total amount of balls." << endl;
        return EXIT_SUCCESS;
    }

    cout << "The probability of guessing all " << drawn_balls << " balls correctly is 1/"
        << all_combinations(total_balls, drawn_balls) << endl;
    return EXIT_SUCCESS;
}
