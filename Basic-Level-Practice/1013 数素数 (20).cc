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
    int m, n, *primes;

  public:
    Solution()
    {
        cin >> m >> n;
        primes = new int[n]{2};
        for (int i = 1, tmp = 3; i < n; tmp += 2)
            for (int j = 0; j < i; ++j) {
                if (tmp % primes[j] == 0) break;
                if (tmp / primes[j] < primes[j]) {
                    primes[i++] = tmp;
                    break;
                }
            }
    }

    void printPrimes()
    {
        int count = 0;
        for (int i = m - 1; i < n; ++i, ++count) {
            cout << (count ? (count % 10 ? " " : "\n") : "");
            cout << primes[i];
        }
    }
};

int main(void)
{
    Solution s;
    s.printPrimes();
    return 0;
}
