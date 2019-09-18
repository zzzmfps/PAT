#include <iostream>
using namespace std;

class Solution
{
  private:
    int k, *nums;
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
    }

    ~Solution() { delete[] nums; }

    void getMaxSubseqSum()
    {
        if (isAllNegative) {
            cout << 0 << ' ' << nums[0] << ' ' << nums[k - 1];
            return;
        }

        int tmp = nums[0], res = nums[0];
        int beg = nums[0], end = nums[0], last = nums[0];

        for (int i = 1; i < k; ++i) {
            if (tmp > 0) {
                tmp += nums[i];
            } else {
                tmp = last = nums[i];
            }
            if (tmp > res) res = tmp, beg = last, end = nums[i];
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
