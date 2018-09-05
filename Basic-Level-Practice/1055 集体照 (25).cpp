#include <algorithm>
#include <iostream>
#include <string>
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
    int n, k, num;
    pair<string, int> *all;
    vector<vector<string>> res;

  public:
    Solution()
    {
        cin >> n >> k;
        num = n / k;

        all = new pair<string, int>[n];
        for (int i = 0; i < n; ++i) cin >> all[i].first >> all[i].second;
        sort(all, all + n, [](const pair<string, int> &x, const pair<string, int> &y) {
            return x.second < y.second || x.second == y.second && x.first > y.first;
        });

        res.resize(k);
    }

    void printPosition()
    {
        for (int i = 0; i < k; ++i) {
            int beg = i * num, end = (i == k - 1 ? n : beg + num);
            helper(res[i], all, beg, end);
        }
        for (int i = k - 1; i >= 0; --i) {
            int l = res[i].size() - 1;
            if (l & 1) {
                for (int j = l; j >= 0; --j) cout << res[i][j] << (j == 0 ? '\n' : ' ');
            } else {
                for (int j = 0; j <= l; ++j) cout << res[i][j] << (j == l ? '\n' : ' ');
            }
        }
    }

  private:
    void helper(vector<string> &x, pair<string, int> *all, int beg, int end)
    {
        int y = end - beg;
        x.reserve(y);
        for (int i = beg + 1; i < end; i += 2) x.push_back(all[i].first);
        for (int i = end - (y & 1 ? 1 : 2); i >= beg; i -= 2) x.push_back(all[i].first);
    }
};

int main(void)
{
    Solution s;
    s.printPosition();
    return 0;
}
