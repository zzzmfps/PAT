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
    int n;

  public:
    Solution() { cin >> n; }

    int countOnes()
    {
        int res = 0, rn = 1, left, mid, right;
        while (n >= rn) {
            left = n / rn / 10;
            mid = n / rn % 10;
            right = n % rn;
            if (mid == 0) {
                res += left * rn;
            } else if (mid == 1) {
                res += left * rn + right + 1;
            } else {
                res += (left + 1) * rn;
            }
            rn *= 10;
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    cout << s.countOnes() << '\n';
    return 0;
}
