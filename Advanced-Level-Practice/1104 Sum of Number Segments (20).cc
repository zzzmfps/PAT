#include <iomanip>
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
    double *nums;

  public:
    Solution()
    {
        cin >> n;
        nums = new double[n];
        for (int i = 0; i < n; ++i) cin >> nums[i];
    }

    double getSum()
    {
        double res = 0.0;
        for (int i = 0; i < n; ++i) res += nums[i] * (i + 1) * (n - i);
        return res;
    }
};

int main(void)
{
    Solution s;
    cout << fixed << setprecision(2) << s.getSum();
    return 0;
}
