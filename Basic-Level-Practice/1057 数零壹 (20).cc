#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    int n = 0;

  public:
    Solution()
    {
        string tmp;
        getline(cin, tmp);
        for (const auto &x : tmp)
            if (x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z') n += toupper(x) - 64;
    }

    void countZeroAndOne()
    {
        int zero = 0, one = 0;
        while (n) {
            (n & 1 ? one : zero) += 1;
            n >>= 1;
        }
        cout << zero << ' ' << one;
    }
};

int main(void)
{
    Solution s;
    s.countZeroAndOne();
    return 0;
}
