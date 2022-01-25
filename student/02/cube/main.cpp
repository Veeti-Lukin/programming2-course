#include <iostream>

int main()
{
    int number = 0;
    int cubed_number = 0;

    std::cout << "Enter a number: ";
    std::cin >> number;

    cubed_number = number * number * number;

    if (cubed_number < 0 or (cubed_number/number/number) != number) {
        std::cout << "ERROR! The cube of " << number << " is not " << cubed_number << "." << std::endl;
        return 0;
    }

    std::cout << "The cube of " << number << " is " << cubed_number << "." << std::endl;
    return 0;
}
