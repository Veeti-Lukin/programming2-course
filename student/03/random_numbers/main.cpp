#include <iostream>
#include <random>
#include <string>

using namespace std;

void produce_random_numbers(unsigned int lower, unsigned int upper) {
    /* generates random numbers in range of parameter <lower> and <upper>
       asks user for seed number and goes on generating new number until user inputs "q" */
    int seed;
    cout << "Enter a seed value: ";
    cin >> seed;

    default_random_engine generator(seed);
    uniform_int_distribution<int> distr(lower, upper);

    while (true) {
        cout << "\n";
        cout << "Your drawn random number is " << distr(generator) << endl;
        cout << "Press q to quit or any other key to continue: ";
        string answer = "";
        cin >> answer;

        if (answer == "q")
            break;
    }
}

int main()
{
    unsigned int lower_bound, upper_bound;
    cout << "Enter a lower bound: ";
    cin >> lower_bound;
    cout << "Enter an upper bound: ";
    cin >> upper_bound;


    if(lower_bound >= upper_bound)
    {
        cout << "The upper bound must be strictly greater than the lower bound"
             << endl;
        return EXIT_FAILURE;
    }

    produce_random_numbers(lower_bound, upper_bound);

    return EXIT_SUCCESS;
}
