#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    struct Project
    {
        int profit, lasting, deadline;
        Project(int p, int l, int d) : profit(p), lasting(l), deadline(d) {}
    };
    int pnums, lastDeadline;
    vector<Project> ps;

public:
    Solution()
    {
        cin >> pnums;
        ps.reserve(pnums);
        for (int i = 0; i < pnums; ++i) {
            int profit, lasting, deadline;
            cin >> profit >> lasting >> deadline;
            ps.emplace_back(profit, lasting, deadline);
        }
        sort(ps.begin(), ps.end(), [](const Project &x, const Project &y) { return x.deadline < y.deadline; });
        lastDeadline = ps.back().deadline;
    }

    int business()
    {
        vector<vector<int>> dp(pnums + 1, vector<int>(lastDeadline + 1, 0));
        for (int i = 1; i <= pnums; ++i) {
            for (int j = 1; j <= lastDeadline; ++j) { // assuming project i is finished at day j
                int tmp = min(j, ps[i - 1].deadline) - ps[i - 1].lasting; // latest day to begin project j
                if (tmp >= 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][tmp] + ps[i - 1].profit);
                } else {  // time is not enough
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[pnums][lastDeadline];
    }
};

int main(void)
{
    Solution s;
    cout << s.business();
    return 0;
}
