#include<cmath>
#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    int printHourGlass(int n, char c)
    {
        // let m equals to num of chars of the longest(first or last) line
        // then used_chars == m * (m + 1) / 2 + (m - 1) / 2
        int m = int(sqrt(2 + 2 * n)) - 1;
        if (!(m & 1)) m -= 1;
        for (int i = m; i > 1; i -= 2) cout << string((m - i) / 2, ' ') << string(i, c) << '\n';
        for (int i = 1; i <= m; i += 2) cout << string((m - i) / 2, ' ') << string(i, c) << '\n';
        return n - m * (m + 1) / 2 - (m - 1) / 2;
    }
};

int main(void)
{
    int n;
    char c;
    cin >> n >> c;
    Solution s;
    cout << s.printHourGlass(n, c);
    return 0;
}
