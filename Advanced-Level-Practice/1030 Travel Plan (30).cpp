#include <iostream>
#include <utility>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution  // dijkstra only
{
  private:
    const int LIMIT = 0x3FFFFFFF;
    int n, m, s, d;
    pair<int, int> **highways;

  public:
    Solution()
    {
        cin >> n >> m >> s >> d;
        highways = new pair<int, int> *[n];
        for (int i = 0; i < n; ++i) {
            highways[i] = new pair<int, int>[n];
            for (int j = 0; j < n; ++j) highways[i][j].first = highways[i][j].second = LIMIT;
        }
        for (int i = 0, c1, c2; i < m; ++i) {
            cin >> c1 >> c2;
            cin >> highways[c1][c2].first >> highways[c1][c2].second;
            highways[c2][c1] = highways[c1][c2];
        }
    }

    ~Solution()
    {
        for (int i = 0; i < n; ++i) delete[] highways[i];
        delete[] highways;
    }

    void dijkstra()
    {
        bool *isVisited = new bool[n]{};
        int *dist = new int[n], *cost = new int[n], *pre = new int[n];
        fill(dist, dist + n, LIMIT), fill(cost, cost + n, LIMIT);
        dist[s] = cost[s] = 0, pre[s] = s;
        for (int i = 0; i < n; ++i) {
            int u = -1, minLen = LIMIT;
            for (int j = 0; j < n; ++j)
                if (!isVisited[j] && dist[j] < minLen) u = j, minLen = dist[j];
            isVisited[u] = true;
            for (int k = 0; k < n; ++k) {
                int newDist = dist[u] + highways[u][k].first, newCost = cost[u] + highways[u][k].second;
                if (newDist < dist[k]) {
                    dist[k] = newDist;
                    cost[k] = newCost;
                    pre[k] = u;
                } else if (newDist == dist[k]) {
                    if (newCost < cost[k]) {
                        cost[k] = newCost;
                        pre[k] = u;
                    }
                }
            }
        }
        output(pre, d);
        cout << dist[d] << ' ' << cost[d];

        delete[] isVisited;
        delete[] dist;
        delete[] cost;
        delete[] pre;
    }

  private:
    void output(int *pre, int iter)
    {
        if (pre[iter] != iter) output(pre, pre[iter]);
        cout << iter << ' ';
    }
};

int main(void)
{
    Solution s;
    s.dijkstra();
    return 0;
}
