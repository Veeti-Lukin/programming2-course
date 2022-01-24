#include <iostream>

using namespace std;

int main()
{
    int number = 0;

    cout << "Enter a positive number: ";
    cin >> number;

    if (number <= 0) {
        cout << "Only positive numbers accepted" << endl;
        return 0;
    }

    int shortest_distance = number;
    int factor1 = 0;
    int factor2 = 0;

    for (int i=1; i < number; i++) {
       int n = number / i;

       if (n * i == number) {
           int distance = n - i;

           if (distance < 0)
               distance = - distance;

           if (distance < shortest_distance) {
               shortest_distance = distance;
               factor1 = i;
               factor2 = n;
           }

       }
    }
    cout << number << "=" << factor1 << "*" << factor2 << endl;
    return 0;
}
