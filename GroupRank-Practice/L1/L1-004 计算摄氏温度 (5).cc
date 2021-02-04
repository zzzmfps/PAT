#include <iostream>
using namespace std;

int main(void)
{
    int fah;
    cin >> fah;
    cout << "Celsius = " << int(5 * (fah - 32) / 9);
    return 0;
}
