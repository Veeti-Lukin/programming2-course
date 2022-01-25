// Example program
#include <iostream>
#include <string>

long int factorial (int number) {
    long int number_factorial = 0;

    if (number == 0) {
        return 1;
    }

    for (int i = 1; i < number; --i) {
        number_factorial *= i;

    }

    return number_factorial;
}

int main()
{
    while (true) {
        int number = 0;
        std::cin >> number;
        std::cout << factorial(number) << std::endl;
  }

}
