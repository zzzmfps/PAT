#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Solution
{
private:
    // test point 3 is like:  1 -60/12
    // let res be equal to 'first input fraction' may not be a good idea
    pair<int, int> res = {0, 1};

public:
    Solution()
    {
        int n;
        cin >> n;
        while (n--) {
            auto f2 = getFraction();
            addFraction(res, f2);
        }
    }

    void printResult()
    {
        if (res.second == 1) {
            cout << res.first;
        } else if (abs(res.first) < res.second) {
            cout << res.first << '/' << res.second;
        } else {
            int integer = res.first / res.second;
            cout << integer << ' ' << res.first - integer * res.second << '/' << res.second;
        }
    }

private:
    pair<int, int> getFraction()
    {
        string f;
        cin >> f;
        int split = f.find('/');
        return make_pair(stoi(f.substr(0, split)), stoi(f.substr(split + 1)));
    }

    void addFraction(pair<int, int> &x, const pair<int, int> &y)
    {
        int _gcd = gcd(x.second, y.second);
        int x2 = x.second / _gcd, y2 = y.second / _gcd;
        x.first = x.first * y2 + y.first * x2;
        x.second *= y2;
        int _gcd2 = gcd(x.first, x.second);
        if (_gcd2 > 1) x.first /= _gcd2, x.second /= _gcd2;
    }

    int gcd(int a, int b)
    {
        return abs(b ? gcd(b, a % b) : a);
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
