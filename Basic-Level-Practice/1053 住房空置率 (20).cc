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
    int n, d;
    double e;

  public:
    Solution() { cin >> n >> e >> d; }

    void checkStatus()
    {
        int r1 = 0, r2 = 0;
        for (int i = 0; i < n; ++i) {
            int k, count = 0;
            cin >> k;
            double num;
            for (int j = 0; j < k; ++j) {
                cin >> num;
                if (num < e) ++count;
            }
            if (count * 2 > k) (k > d ? r2 : r1) += 1;
        }
        cout << fixed << setprecision(1);
        cout << 100.0 * r1 / n << "% " << 100.0 * r2 / n << '%';
    }
};

int main(void)
{
    Solution s;
    s.checkStatus();
    return 0;
}
