#include <cmath>
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
    struct Factors {
        int factor, count;
    };
    Factors rec[10]{};
    int num;

  public:
    Solution() { cin >> num; }

    void printResult()
    {
        cout << num << '=';
        int end = getPrimeFactors();
        for (int i = 0; i < end; ++i) {
            cout << (i ? "*" : "") << rec[i].factor;
            if (rec[i].count > 1) cout << '^' << rec[i].count;
        }
    }

  private:
    int getPrimeFactors()
    {
        int limit = sqrt(num) + 1, trav = 0;
        if (!(num & 1)) {
            while (!(num & 1)) {
                ++rec[trav].count;
                num >>= 1;
            }
            rec[trav++].factor = 2;
        }
        for (int i = 3; num > 1 && i < limit; i += 2) {
            if (num % i == 0) {
                while (num % i == 0) {
                    ++rec[trav].count;
                    num /= i;
                }
                rec[trav++].factor = i;
            }
        }
        if (num > 1 || trav == 0) {
            rec[trav].factor = num;
            rec[trav++].count = 1;
        }
        return trav;
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
