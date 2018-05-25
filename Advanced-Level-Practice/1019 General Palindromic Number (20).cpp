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
    int num, base;
    cin >> num >> base;
    if (num == 0) {
        cout << "Yes\n0";
    } else {
        int bits = log(num) / log(base) + 1, idx1 = 0, idx2 = 0;
        int *res = new int[bits];
        while (num) {
            res[idx2++] = num % base;
            num /= base;
        }
        idx2 -= 1;
        bool isPalindrome = true;
        while (idx1 < idx2)
            if (res[idx1++] != res[idx2--]) {
                isPalindrome = false;
                break;
            }
        cout << (isPalindrome ? "Yes" : "No") << '\n' << res[idx1 + idx2];
        for (int i = idx1 + idx2 - 1; i > -1; --i) cout << ' ' << res[i];
    }
    system("pause");
    return 0;
}
