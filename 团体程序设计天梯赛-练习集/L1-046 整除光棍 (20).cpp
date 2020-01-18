#include <iostream>
using namespace std;

int main(void)
{ // test case may be NOT perfect: what is the answer for num=514,515,516? (obviously TLE)
    int num;
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
    string div(bits, '1'), quo = "";
    for (auto c : div) {
        remains = remains * 10 + 1;
        if (quo.empty() && remains < num) continue;
        int tmp = remains / num;
        quo += char(48 + tmp);
        remains -= tmp * num;
    }
    cout << quo << ' ' << bits;
    return 0;
}
