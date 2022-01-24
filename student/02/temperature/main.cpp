#include <iostream>

using namespace std;

int main()
{
    int original_temperature = 0;

    cout << "Enter a temperature: ";
    cin >> original_temperature;

    cout << original_temperature << " degrees Celsius is " << original_temperature * 1.8 + 32 << " degrees Farenheit" << endl;
    cout << original_temperature << " degrees Farenheit is " << (original_temperature - 32) / 1.8 << " degrees Celsius" << endl;

    return 0;
}
