#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    int n, *nums;

  public:
    Solution()
    {
        cin >> n;
        nums = new int[n];
        for (int i = 0; i < n; ++i) cin >> nums[i];
    }

    void printResult()
    {
        cout << (n & 1 ? 1 : 0) << ' ';
        int mid = n / 2;
        nth_element(nums, nums + mid, nums + n);
        cout << accumulate(nums + mid, nums + n, 0) - accumulate(nums, nums + mid, 0);
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
