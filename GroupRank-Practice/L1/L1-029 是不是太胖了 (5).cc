#include <iomanip>
#include <iostream>
using namespace std;

int main(void)
{
    int height;
    cin >> height;
    cout << fixed << setprecision(1) << (height - 100) * 1.8;
    return 0;
}
