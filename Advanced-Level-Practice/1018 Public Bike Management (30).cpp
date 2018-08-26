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
    const int LIMIT = 0x3FFFFFFF;
    int half, n, sp, m;
    int *numbers;
    vector<pair<int, int>> *nextStation;
    vector<int> *pre;

    vector<int> tmp, path;
    int minSent, minTakenBack;

  public:
    Solution()
    {
        cin >> half >> n >> sp >> m;
        half /= 2;

        numbers = new int[n + 1];
        numbers[0] = 0;
        for (int i = 1; i <= n; ++i) cin >> numbers[i];

        nextStation = new vector<pair<int, int>>[n + 1];
        for (int i = 0, s1, s2, t; i < m; ++i) {
            cin >> s1 >> s2 >> t;
            nextStation[s1].emplace_back(s2, t);
            nextStation[s2].emplace_back(s1, t);
        }

        pre = new vector<int>[n + 1];

        minSent = minTakenBack = LIMIT;
    }

    ~Solution()
    {
        delete[] numbers;
        delete[] nextStation;
        delete[] pre;
    }

    void dijkstra()  // dijkstra + dfs
    {
        bool *isVisited = new bool[n + 1]{};
        int *dist = new int[n + 1];
        dist[0] = 0, fill(dist + 1, dist + n + 1, LIMIT);

        for (int i = 0; i <= n; ++i) {
            int u = -1, minLen = LIMIT;
            for (int j = 0; j <= n; ++j)
                if (!isVisited[j] && dist[j] < minLen) u = j, minLen = dist[j];
            isVisited[u] = true;
            for (int k = 0, size = nextStation[u].size(); k < size; ++k) {
                auto &p = nextStation[u][k];
                if (isVisited[p.first]) continue;
                int newDist = dist[u] + p.second;
                if (newDist < dist[p.first]) {
                    pre[p.first].clear();
                    dist[p.first] = newDist;
                }
                if (newDist == dist[p.first]) pre[p.first].push_back(u);
            }
        }

        dfs(sp);
        output();

        delete[] isVisited;
        delete[] dist;
    }

  private:
    void dfs(int x)
    {
        tmp.push_back(x);
        if (x == 0) {
            int sent = 0, takenBack, cur = 0, req = 0;
            for (int i = tmp.size() - 2; i >= 0; --i) {
                cur += numbers[tmp[i]], req += half;
                if (cur < req) sent += req - cur, cur = req;
            }
            takenBack = cur - req;
            if (sent < minSent || sent == minSent && takenBack < minTakenBack)
                path = tmp, minSent = sent, minTakenBack = takenBack;
            tmp.pop_back();
            return;
        }
        for (const auto y : pre[x]) dfs(y);
        tmp.pop_back();
    }

    void output()
    {
        cout << minSent << " 0";
        for (int i = path.size() - 2; i >= 0; --i) cout << "->" << path[i];
        cout << ' ' << minTakenBack;
    }
};

int main(void)
{
    Solution s;
    s.dijkstra();
    return 0;
}
