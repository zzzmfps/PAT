#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
private:
    string str;
    int length;
    vector<vector<int>> dp;

public:
    Solution()
    {
        getline(cin, str);
        length = str.size();
        dp = vector<vector<int>>(length, vector<int>(length, 1));
    }

    int longestSymStr()
    {
        int ret = 1;
        for (int i = length - 2; i > -1; --i) {
            for (int j = i + 1; j < length; ++j) {
                if (str[i] != str[j]) continue;
                if (i + 1 == j) {
                    dp[i][j] = 2;
                } else if (dp[i + 1][j - 1] + 1 == j - i) {
                    dp[i][j] = j - i + 1;
                }
                ret = max(ret, dp[i][j]);
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    cout << s.longestSymStr();
    return 0;
}
