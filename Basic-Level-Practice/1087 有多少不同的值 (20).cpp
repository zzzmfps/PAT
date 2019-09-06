#include <iostream>
using namespace std;

class Solution
{
public:
    void getNums()
    {
        int n, count = 0;
        bool nums[10334] = {};
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            int tmp = i / 2 + i / 3 + i / 5;
            if (!nums[tmp]) {
                nums[tmp] = true;
                count += 1;
            }
        }
        cout << count;
    }
};

int main(void)
{
    Solution s;
    s.getNums();
    return 0;
}
