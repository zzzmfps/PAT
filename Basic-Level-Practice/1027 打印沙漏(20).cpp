#include <cmath>
#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    int m;
    char fill;
    cin >> m >> fill;
    int n = m + 1, half;
    for (int i = 0;; ++i) {
        int tmp = n - 4 * i - 2;
        if (tmp >= 0) {
            n = tmp;
        } else {
            n = 2 * i - 1;
            half = i;
            break;
        }
    }
    // does NOT print space on the right side
    for (int i = 0; i < half; ++i) cout << string(i, ' ') << string(n - 2 * i, fill) << '\n';
    for (int i = half - 2; i > 0; --i) cout << string(i, ' ') << string(n - 2 * i, fill) << '\n';
    if (n > 1) cout << string(n, fill);
    int tmp = (n - 1) / 2;
    tmp = tmp * tmp * 2 + m - n * n;
    if (n > 1) cout << '\n';
    cout << tmp;  // print even tmp is 0
    system("pause");
    return 0;
}
