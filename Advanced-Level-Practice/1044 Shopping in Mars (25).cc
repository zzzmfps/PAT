#include <iostream>
#include <utility>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    int numbers, amount, *accum;

  public:
    Solution()
    {
        cin >> numbers >> amount;
        int *values = new int[numbers];
        for (int i = 0; i < numbers; ++i) cin >> values[i];
        accum = new int[numbers];
        accum[0] = values[0];
        for (int i = 1; i < numbers; ++i) accum[i] = accum[i - 1] + values[i];
    }

    void getPossibleSolutions()
    {
        vector<pair<int, int>> res;
        int lost = 0x7FFFFFFF;
        for (int i = 0; i < numbers; ++i) {
            int left = i, right = numbers - 1;
            while (left <= right) {  // traverse on accum[]
                int mid = left + (right - left) / 2;
                int tmp = accum[mid] - (i == 0 ? 0 : accum[i - 1]);
                if (tmp == amount) {
                    if (lost > 0) {
                        lost = 0;
                        res.clear();
                    }
                    res.push_back(make_pair(i + 1, mid + 1));
                    break;
                } else if (tmp < amount) {
                    left = mid + 1;
                } else {
                    int tmp2 = tmp - amount;
                    if (tmp2 <= lost) {
                        if (tmp2 < lost) {
                            lost = tmp2;
                            res.clear();
                        }
                        res.push_back(make_pair(i + 1, mid + 1));
                    }
                    right = mid - 1;
                }
            }
        }
        for (const auto &p : res) cout << p.first << '-' << p.second << '\n';
    }
};

int main(void)
{
    Solution s;
    s.getPossibleSolutions();
    return 0;
}
