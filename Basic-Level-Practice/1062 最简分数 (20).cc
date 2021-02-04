#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    double num1, num2;
    int den;

  public:
    Solution()
    {
        int a, b, c, d;
        (cin >> a).get();
        (cin >> b >> c).get();
        cin >> d >> den;
        num1 = double(den) * a / b;
        num2 = double(den) * c / d;
        if (num1 > num2) swap(num1, num2);
    }

    void printResult()
    {
        vector<int> res;
        int x = int(num2 == int(num2) ? num2 : num2 + 1);
        for (int i = int(num1 + 1); i < x; ++i)
            if (__gcd(i, den) == 1) res.push_back(i);
        cout << res[0] << '/' << den;
        for (int i = 1, size = res.size(); i < size; ++i) cout << ' ' << res[i] << '/' << den;
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
