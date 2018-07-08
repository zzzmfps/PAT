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
    int nums[10];

  public:
    Solution()
    {
        for (int i = 0; i < 10; ++i) cin >> nums[i];
    }

    void printMinNum()
    {
        for (int i = 1; i < 10; ++i)
            if (nums[i]) {
                cout << i;
                --nums[i];
                break;
            }
        for (int i = 0; i < 10; ++i) cout << string(nums[i], '0' + i);
    }
};

int main(void)
{
    Solution s;
    s.printMinNum();
    return 0;
}
