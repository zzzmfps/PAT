#include <iostream>
using namespace std;

class Solution
{
public:
    void bestMooncake()
    {
        int n, m;
        cin >> n >> m;
        int *nums = new int[n + 1] {};
        int iMax = 0;
        while (m--) {
            for (int i = 1, tmp; i <= n; ++i) {
                cin >> tmp;
                nums[i] += tmp;
                iMax = max(iMax, nums[i]);
            }
        }
        cout << iMax << '\n';
        bool flag = false;
        for (int i = 1; i <= n; ++i) {
            if (nums[i] == iMax) {
                if (flag) cout << ' ';
                cout << i;
                flag = true;
            }
        }
        delete[] nums;
    }
};

int main(void)
{
    Solution s;
    s.bestMooncake();
    return 0;
}
