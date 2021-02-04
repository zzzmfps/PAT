#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    void count()
    {
        string s;
        cin >> s;
        int counts[10] = {};
        for (auto c : s) ++counts[c - 48];
        for (int i = 0; i < 10; ++i)
            if (counts[i]) cout << i << ':' << counts[i] << '\n';
    }
};

int main(void)
{
    Solution s;
    s.count();
    return 0;
}
