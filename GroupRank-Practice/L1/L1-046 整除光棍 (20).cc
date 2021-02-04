#include <iostream>
using namespace std;

int main(void)
{
    int num; // odd and not ends with '5'
    cin >> num;
    int bits = 1, remains = 1;
    while (true) {
        // calculates remainder, not dividend itself, avoiding overflow
        int tmp = remains / num * num;
        if ((remains -= tmp) == 0) break;
        bits += 1;
        remains = remains * 10 + 1;
    }
    // find least s(consists of '1' only)
    string quo = "";
    for (int i = 0; i < bits; ++i) {
        remains = remains * 10 + 1;
        if (quo.empty() && remains < num) continue;
        int tmp = remains / num;
        quo += char(48 + tmp);
        remains -= tmp * num;
    }
    cout << quo << ' ' << bits;
    return 0;
}
