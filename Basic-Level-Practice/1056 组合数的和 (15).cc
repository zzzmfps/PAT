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
    int n;

  public:
    Solution() { cin >> n; }

    int getTotal()
    {
        int total = 0;
        for (int i = 0, j; i < n; ++i) {
            cin >> j;
            total += (n - 1) * j * 11;
        }
        return total;
    }
};

int main(void)
{
    Solution s;
    cout << s.getTotal();
    return 0;
}
