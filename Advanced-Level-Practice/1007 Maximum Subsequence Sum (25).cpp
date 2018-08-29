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
    int k, *nums, *dp;
    bool isAllNegative = true;

  public:
    Solution()
    {
        cin >> k;
        nums = new int[k];
        for (int i = 0; i < k; ++i) {
            cin >> nums[i];
            if (nums[i] >= 0) isAllNegative = false;
        }
        dp = new int[k];
        dp[0] = nums[0];
    }

    ~Solution() { delete[] nums, dp; }

    void getMaxSubseqSum()
    {
        if (isAllNegative) {
            cout << 0 << ' ' << nums[0] << ' ' << nums[k - 1];
            return;
        }
        int res = nums[0], beg = nums[0], end = nums[0], last;
        for (int i = 1; i < k; ++i) {
            if (dp[i - 1] > 0) {
                dp[i] = dp[i - 1] + nums[i];
            } else {
                last = dp[i] = nums[i];
            }
            if (dp[i] > res) res = dp[i], beg = last, end = nums[i];
        }
        cout << res << ' ' << beg << ' ' << end;
    }
};

int main(void)
{
    Solution s;
    s.getMaxSubseqSum();
    return 0;
}
