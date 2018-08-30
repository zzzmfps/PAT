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
    int n, m, l;
    int *favorite, *stripe, *dp;

  public:
    Solution()
    {
        cin >> n >> m;
        favorite = new int[n + 1]{};
        for (int i = 1, tmp; i <= m; ++i) {
            cin >> tmp;
            favorite[tmp] = i;
        }

        cin >> l;
        stripe = new int[l];
        for (int i = 0; i < l; ++i) cin >> stripe[i];

        dp = new int[l];
        fill(dp, dp + l, 1);
    }

    ~Solution() { delete[] stripe, dp; }

    int getMaxLength()
    {
        int res = 1;
        for (int i = 1; i < l; ++i) {
            if (!favorite[stripe[i]]) continue;
            for (int j = 0; j < i; ++j) {
                if (!favorite[stripe[j]]) continue;
                if (favorite[stripe[i]] >= favorite[stripe[j]]) dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    cout << s.getMaxLength();
    return 0;
}
