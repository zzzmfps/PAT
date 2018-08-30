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
    string str;
    int size, res;
    bool **dp;

  public:
    Solution()
    {
        getline(cin, str);
        size = str.size(), res = 1;
        dp = new bool *[size];
        for (int i = 0; i < size; ++i) dp[i] = new bool[size]{};
    }

    ~Solution()
    {
        for (int i = 0; i < size; ++i) delete[] dp[i];
        delete[] dp;
    }

    int getLongestSymStrLength()
    {
        for (int i = 0; i < size; ++i) {
            dp[i][i] = true;
            if (i + 1 < size && str[i] == str[i + 1]) dp[i][i + 1] = true, res = 2;
        }
        for (int delta = 2, end = size - res; delta < size; ++delta) {
            for (int i = 0; i < end; ++i) {
                if (i + delta >= size) break;
                if (str[i] == str[i + delta]) {
                    dp[i][i + delta] = dp[i + 1][i + delta - 1];
                    if (dp[i][i + delta] && res <= delta) {
                        res = delta + 1;
                        end = size - res;
                    }
                }
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    cout << s.getLongestSymStrLength();
    return 0;
}
