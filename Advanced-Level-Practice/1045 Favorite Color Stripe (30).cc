/* Longest Increasing Subsequence (LIS)
** Takes less space but more time.
*/
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

    ~Solution() { delete[] favorite, stripe, dp; }

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




/* Longest Common Subsequence (LCS)
** Takes less time but more space.
*/
class Solution
{
  private:
    int n, m, l;
    int *favorite, *stripe, **dp;

  public:
    Solution()
    {
        cin >> n >> m;
        favorite = new int[m + 1];
        for (int i = 1; i <= m; ++i) cin >> favorite[i];

        cin >> l;
        stripe = new int[l + 1];
        for (int i = 1; i <= l; ++i) cin >> stripe[i];

        dp = new int *[m + 1];
        dp[0] = new int[l + 1]{};
        for (int i = 1; i <= m; ++i) {
            dp[i] = new int[l + 1];
            dp[i][0] = 0;
        }
    }

    ~Solution()
    {
        for (int i = 0; i <= m; ++i) delete[] dp[i];
        delete[] favorite, stripe, dp;
    }

    int getMaxLength()
    {
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= l; ++j)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (favorite[i] == stripe[j] ? 1 : 0);
        return dp[m][l];
    }
};
