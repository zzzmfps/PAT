#include <iostream>
using namespace std;

int main(void)
{
    int n, height, weight;
    cin >> n;
    while (n--) {
        cin >> height >> weight;
        int stdW = (height - 100) * 1.8;
        if (abs(weight - stdW) < 0.1 * stdW) {
            cout << "You are wan mei!\n";
        } else {
            cout << (weight > stdW ? "You are tai pang le!" : "You are tai shou le!") << '\n';
        }
    }
    return 0;
}
