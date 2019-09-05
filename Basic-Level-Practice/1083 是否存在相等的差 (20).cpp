#include <functional>
#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    void equalDifferences()
    {
        int n, x;
        cin >> n;
        map<int, int, greater<int>> diff;
        for(int i=1;i<=n;++i) {
            cin >> x;
            diff[abs(x - i)] += 1;
        }
        for (const auto &p : diff)
            if (p.second > 1) cout << p.first << ' ' << p.second << '\n';
    }
};

int main(void)
{
    Solution s;
    s.equalDifferences();
    return 0;
}
