#include <iostream>
#include <set>
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
    set<int> sums;

  public:
    Solution()
    {
        cin >> n;
        for (int i = 0, j; i < n; ++i) {
            cin >> j;
            sums.insert(getDigitsSum(j));
        }
    }

    void printResult()
    {
        cout << sums.size() << '\n';
        for (auto it = sums.begin(); it != sums.end(); ++it) cout << (it == sums.begin() ? "" : " ") << *it;
    }

  private:
    int getDigitsSum(int x) const
    {
        int ret = 0;
        while (x) {
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
