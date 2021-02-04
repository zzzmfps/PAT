#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
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
    const int BEG = 480, END = 1020, MAXT = 540;  // beg time: 8 * 60, end time: 17 * 60
    int n, m, k, q;                               // windows, line length, customers, queries
    int *times, *queries, costs[1001]{};          // costs index always out of bounds as a dynamic array

  public:
    Solution()
    {
        cin >> n >> m >> k >> q;
        times = new int[k + 1];
        for (int i = 1; i <= k; ++i) cin >> times[i];
        queries = new int[q];
        for (int i = 0; i < q; ++i) cin >> queries[i];
        process();
    }

    void response()
    {
        for (int i = 0; i < q; ++i)
            if (costs[queries[i]] == 0) {
                cout << "Sorry\n";
            } else {
                int tmp = costs[queries[i]] + BEG;
                cout << setfill('0') << setw(2) << tmp / 60 << ':' << setw(2) << tmp % 60 << '\n';
            }
    }

  private:
    void process()
    {
        vector<queue<pair<int, int>>> lines(n);

        int idx = 1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                lines[j].emplace(times[idx], idx);
                if (++idx > k) break;
            }

        int acc = 0;
        while (idx <= k) {
            sort(lines.begin(), lines.end(),
                 [](const queue<pair<int, int>> &x, const queue<pair<int, int>> &y) { return x.front() < y.front(); });
            auto &tmp = lines[0].front();
            acc += tmp.first;
            costs[tmp.second] = acc;
            if (acc >= MAXT) {
                for (int i = 1; i < n; ++i) {
                    auto &tmp2 = lines[i].front();
                    costs[tmp2.second] = tmp2.first + acc - tmp.first;
                }
                return;
            }
            for (int i = 1; i < n; ++i) lines[i].front().first -= tmp.first;
            lines[0].pop(), lines[0].emplace(times[idx], idx);
            ++idx;
        }

        for (auto &x : lines) {
            int accx = acc;
            while (!x.empty()) {
                if (accx >= MAXT) break;
                accx += x.front().first;
                costs[x.front().second] = accx;
                x.pop();
            }
        }
    }
};

int main(void)
{
    Solution s;
    s.response();
    return 0;
}
