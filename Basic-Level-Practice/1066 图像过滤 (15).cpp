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
    int m, n, a, b, g;

  public:
    Solution() { cin >> m >> n >> a >> b >> g; }

    void printResult()
    {
        cout << setfill('0');
        for (int i = 0; i < m; ++i)
            for (int j = 1, k; j <= n; ++j) {
                cin >> k;
                cout << setw(3) << (k >= a && k <= b ? g : k) << (j == n ? "\n" : " ");
            }
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
