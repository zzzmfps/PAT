#include <iostream>
using namespace std;

class Solution
{
public:
    void ability()
    {
        int m, x, y;
        cin >> m >> x >> y;
        int a = 99, b;
        double c;
        while (a > 9) {
            b = a / 10 + a % 10 * 10;
            double cx = abs(a - b), cy = b;
            if (cx / x == cy / y) {
                c = cx / x;
                cout << a;
                cout << ' ' << (m > a ? "Gai" : m == a ? "Ping" : "Cong");
                cout << ' ' << (m > b ? "Gai" : m == b ? "Ping" : "Cong");
                cout << ' ' << (m > c ? "Gai" : m == c ? "Ping" : "Cong");
                return;
            }
            a -= 1;
        }
        cout << "No Solution";
    }
};

int main(void)
{
    Solution s;
    s.ability();
    return 0;
}
