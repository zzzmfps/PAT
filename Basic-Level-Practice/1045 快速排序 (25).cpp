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
    int n, *nums, *leftMax;

  public:
    Solution()
    {
        cin >> n;
        nums = new int[n];
        leftMax = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            leftMax[i] = max(getLastleftMax(i), nums[i]);
        }
    }

    void printPivots()
    {
        int p = 0, *pivot = new int[n], rightMin = 0x7FFFFFFF;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > getLastleftMax(i) && nums[i] < rightMin) pivot[p++] = nums[i];
            rightMin = min(rightMin, nums[i]);
        }
        sort(pivot, pivot + p, greater<int>());
        cout << p << '\n';
        while (p--) cout << pivot[p] << (p ? " " : "");
        cout << '\n';  // why need this ???
    }

  private:
    int getLastleftMax(int i) { return i ? leftMax[i - 1] : 0; }
};

int main(void)
{
    Solution s;
    s.printPivots();
    return 0;
}
