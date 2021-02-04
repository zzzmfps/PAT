#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    int n, m, *values;
    pair<int, int *> *dp;

  public:
    Solution()
    {
        cin >> n >> m;
        values = new int[n];
        for (int i = 0; i < n; ++i) cin >> values[i];
        sort(values, values + n, greater<int>());

        dp = new pair<int, int *>[m + 1] {};
        for (int i = 0; i <= m; ++i) dp[i].second = new int[n]{};
    }

    ~Solution()
    {
        for (int i = 0; i <= m; ++i) delete[] dp[i].second;
        delete[] values, dp;
    }

    void findSolution()
    {
        for (int i = 0; i < n; ++i) {
            for (int v = m; v >= values[i]; --v) {
                int v2 = dp[v - values[i]].first + values[i];
                if (dp[v].first <= v2) dp[v].first = v2, dp[v].second[i] = values[i];
            }
        }
        if (dp[m].first != m) {
            cout << "No Solution";
            return;
        }
        vector<int> res;  // input may contain coins with the same value
        int num = 0;
        for (int i = m, j = n - 1; i >= 0 && j >= 0; --j) {
            int &tmp = dp[i].second[j];
            if (tmp) res.push_back(tmp), i -= tmp;
        }
        cout << res.front();
        for (int i = 1, size = res.size(); i < size; ++i) cout << ' ' << res[i];
    }
};

int main(void)
{
    Solution s;
    s.findSolution();
    return 0;
}
