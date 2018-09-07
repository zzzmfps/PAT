#include <cmath>
#include <iomanip>
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
    int n, maxn = 0;

  public:
    Solution()
    {
        cin >> n;
        for (int i = 0, j, k; i < n; ++i) {
            cin >> j >> k;
            int x = j * j + k * k;
            maxn = max(maxn, x);
        }
    }

    void printResult() { cout << fixed << setprecision(2) << sqrt(double(maxn)); }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
