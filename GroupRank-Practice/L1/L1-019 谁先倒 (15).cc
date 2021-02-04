#include <iostream>
using namespace std;

int main(void)
{
    int a, b, n;
    cin >> a >> b >> n;
    int ax = a, bx = b;
    while (n--) {
        int a1, a2, b1, b2;
        (cin >> a1 >> a2 >> b1 >> b2).get();
        bool flag1 = (a1 + b1 == a2);
        bool flag2 = (a1 + b1 == b2);
        if (flag1 == flag2) continue;
        flag1 ? --ax : --bx;
        if (flag1 && ax < 0) {
            cout << "A\n" << b - bx;
            break;
        } else if (bx < 0) {
            cout << "B\n" << a - ax;
            break;
        }
    }
    return 0;
}
