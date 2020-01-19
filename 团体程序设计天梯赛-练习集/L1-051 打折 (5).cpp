#include <iomanip>
#include <iostream>
using namespace std;

int main(void)
{
    int price, off;
    cin >> price >> off;
    cout << fixed << setprecision(2) << 0.1 * price * off;
    return 0;
}
