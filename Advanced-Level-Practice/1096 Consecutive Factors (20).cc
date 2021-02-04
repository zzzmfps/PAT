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
    int num, res, len = 0;

  public:
    Solution() { cin >> num; }

    void printResult()
    {
        for (int i = 2, limit = sqrt(num) + 2; i < limit; ++i) {
            int tmp = num;
            for (int j = i, curBeg, curLen = 0; j < limit; ++j) {
                bool flag = tmp % j == 0;
                if (flag) {
                    if (!curLen) curBeg = j;
                    ++curLen;
                    tmp /= j;
                }
                if (!flag || tmp == 1) {
                    if (curLen > len) {
                        res = curBeg;
                        len = curLen;
                    }
                    break;
                }
            }
        }
        if (len == 0) {
            cout << "1\n" << num;
        } else {
            cout << len << '\n';
            for (int i = 0; i < len; ++i) cout << (i ? "*" : "") << res + i;
        }
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
