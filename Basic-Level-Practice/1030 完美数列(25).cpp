#include <algorithm>
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
    int n, p;
    long long *nums;

  public:
    Solution()
    {
        cin >> n >> p;
        nums = new long long[n];
        for (int i = 0; i < n; ++i) cin >> nums[i];
        sort(nums, nums + n);
    }

    int maxNumbers()
    {
        int len = 0, right = 0;
        for (int i = 0; i < n - len; ++i) {
            right = upperBound(right, n, p * nums[i]);
            len = max(len, right - i);
        }
        return len;
    }

  private:
    int upperBound(int beg, int end, long long val)
    {
        while (beg < end) {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] <= val) {
                beg = mid + 1;
            } else {
                end = mid;
            }
        }
        return beg;
    }
};

int main(void)
{
    Solution s;
    cout << s.maxNumbers();
    return 0;
}
