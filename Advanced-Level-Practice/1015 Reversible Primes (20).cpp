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
    static const int maxn = 100000;
    bool isNotPrimes[maxn]{true, true};

  public:
    void isReversiblePrimes()
    {
        for (int i = 2; i <= maxn; ++i) {
            if (isNotPrimes[i]) continue;
            for (int j = 2 * i; j <= maxn; j += i) isNotPrimes[j] = true;
        }
        int n, d;
        while (true) {
            cin >> n;
            if (n < 0) break;
            cin >> d;
            if (isNotPrimes[n] || isNotPrimes[convert(n, d)]) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        }
    }

  private:
    int convert(int num, int radix = 10)
    {
        int ret = 0;
        while (num) {
            ret = ret * radix + num % radix;
            num /= radix;
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    s.isReversiblePrimes();
    return 0;
}
