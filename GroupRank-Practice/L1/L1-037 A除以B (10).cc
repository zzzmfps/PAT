#include <iomanip>
#include <iostream>
using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    bool flag = (b < 0);
    cout << a << '/' << (flag ? "(" : "") << b << (flag ? ")" : "") << '=';
    if (b == 0) {
        cout << "Error";
    } else {
        cout << fixed << setprecision(2) << a / double(b);
    }
    return 0;
}
