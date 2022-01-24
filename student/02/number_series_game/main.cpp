#include <iostream>


int main()
{
    int number_amount = 0;

    std::cout << "How many numbers would you like to have? ";
    std::cin >> number_amount;

    for (int i=0; i < number_amount+1; ++i) {
        std::cout << i << std::endl;
    }
    return 0;
}
