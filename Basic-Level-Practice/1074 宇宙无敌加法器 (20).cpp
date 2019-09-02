#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    void sum()
    {
        string carryMap, x, y;
        cin >> carryMap >> x >> y;

        int carry = 0, i = 0, size = carryMap.size();
        if (size > x.size()) x = string(size - x.size(), '0') + x;
        if (size > y.size()) y = string(size - y.size(), '0') + y;

        while (i++ < size) {
            int t = x[size - i] + y[size - i] - 96 + carry;
            int c = carryMap[carryMap.size() - i] - 48;
            if (c == 0) c = 10;
            carry = t / c;
            x[size - i] = 48 + t - c * carry;
        }
        if (carry) x = to_string(carry) + x;
        auto idx = x.find_first_not_of('0');
        cout << (idx == string::npos ? "0" : x.substr(idx));
    }
};

int main(void)
{
    Solution s;
    s.sum();
    return 0;
}
