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
    bool *isNotPrimes;

  public:
    Solution()
    {
        cin >> n;
        isNotPrimes = new bool[n + 1]{};
        for (int i = 3; i <= n; i += 2) {
            if (isNotPrimes[i]) continue;
            for (int j = 3 * i, delta = 2 * i; j <= n; j += delta) isNotPrimes[j] = true;
        }
    }

    int getPrimePairNumbers()
    {
        int count = 0;
        for (int i = 5; i <= n;)
            if (!isNotPrimes[i]) {
                if (!isNotPrimes[i - 2]) ++count;
                i += 2;
            } else {
                i += 4;
            }
        return count;
    }
};

int main(void)
{
    Solution s;
    cout << s.getPrimePairNumbers();
    return 0;
}
