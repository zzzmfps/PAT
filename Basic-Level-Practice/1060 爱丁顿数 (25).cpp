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
    int n, *miles;

  public:
    Solution()
    {
        cin >> n;
        miles = new int[n + 1]{};
        for (int i = 0, j; i < n; ++i) {
            cin >> j;
            if (j > 0) ++miles[(j > n ? n : j - 1)];
        }
    }

    ~Solution() { delete[] miles; }

    int getNumber()
    {
        for (int i = n; i > 0; --i) {
            if (miles[i] >= i) return i;
            miles[i - 1] += miles[i];
        }
    }
};

int main(void)
{
    Solution s;
    cout << s.getNumber();
    return 0;
}
