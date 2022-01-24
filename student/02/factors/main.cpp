#include <iostream>

using namespace std;

int main()
{
    int original_number = 0;

    cout << "Enter a positive number: ";
    cin >> original_number;

    if (original_number <= 0) {
        cout << "Only positive numbers accepted" << endl;
        return 0;
    }

    return 0;
}
