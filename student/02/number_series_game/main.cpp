#include <iostream>

const int ZIP = 3;
const int BOING = 7;

int main()
{
    int number_amount = 0;

    std::cout << "How many numbers would you like to have? ";
    std::cin >> number_amount;

    for (int i=1; i < number_amount+1; ++i) {
        if (i % ZIP == 0 and i % BOING == 0){
            std::cout << "zip boing" <<std::endl;
        }
        else if (i % ZIP == 0) {
            std::cout << "zip" << std::endl;
        }
        else if (i % BOING == 0) {
            std::cout << "boing" << std::endl;
        }
        else {
            std::cout << i << std::endl;
        }
    }
    return 0;
}
