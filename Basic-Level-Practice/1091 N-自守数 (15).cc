#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
    void check()
    {
        int m, k;
        cin >> m;
        while (m--) {
            cin >> k;
            int tmp = helper(k);
            if (tmp) {
                cout << tmp << ' ' << tmp * k * k << '\n';
            } else {
                cout << "No\n";
            }
        }
    }

private:
    int helper(int k)
    {
        int v = k * k, u = pow(10, int(log10(k)) + 1);
        for (int i = 1; i < 10; ++i) {
            int tmp = i * v;
            if (tmp % u == k) return i;
        }
        return 0;
    }
};

int main(void)
{
    Solution s;
    s.check();
    return 0;
}
