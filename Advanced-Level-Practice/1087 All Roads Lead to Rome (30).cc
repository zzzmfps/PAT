#include <iostream>
#include <string>
#include <unordered_map>
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
    int n, k, start, end;
    int *happiness, **roads;
    unordered_map<string, int> toNumber;
    unordered_map<int, string> toString;

  public:
    Solution()
    {
        string tmp1;
        cin >> n >> k >> tmp1;
        toNumber[tmp1] = 0, toString[0] = tmp1;

        happiness = new int[n];
        happiness[0] = 0;
        for (int i = 1, h; i < n; ++i) {
            cin >> tmp1 >> h;
            toNumber[tmp1] = i, toString[i] = tmp1;
            happiness[i] = h;
        }

        start = 0, end = toNumber["ROM"];

        roads = new int *[n];
        for (int i = 0; i < n; ++i) {
            roads[i] = new int[n];
            fill(roads[i], roads[i] + n, LIMIT);
        }
        string tmp2;
        for (int i = 0, dist, c1, c2; i < k; ++i) {
            cin >> tmp1 >> tmp2 >> dist;
            c1 = toNumber[tmp1], c2 = toNumber[tmp2];
            roads[c1][c2] = roads[c2][c1] = dist;
        }
    }

    ~Solution()
    {
        for (int i = 0; i < n; ++i) delete[] roads[i];
        delete[] happiness, roads;
    }

    void dijkstra()
    {
        /* 1, least cost
        ** 2, max happiness
        ** 3, max avg happiness, or least cities visited
        */
        bool *isVisited = new bool[n]{};
        int *cost = new int[n], *pre = new int[n], *total = new int[n];
        cost[0] = pre[0] = total[0] = 0, fill(cost + 1, cost + n, LIMIT);
        int *pt = new int[n]{}, *num = new int[n]{1};

        for (int i = 0; i < n; ++i) {
            int u = -1, minCost = LIMIT;
            for (int j = 0; j < n; ++j)
                if (!isVisited[j] && cost[j] < minCost) u = j, minCost = cost[j];
            isVisited[u] = true;
            for (int k = 0; k < n; ++k)
                if (!isVisited[k] && roads[u][k] != LIMIT) {
                    int newCost = cost[u] + roads[u][k], newHappiness = total[u] + happiness[k];
                    if (newCost < cost[k]) {
                        cost[k] = newCost, pre[k] = u, total[k] = newHappiness;
                        pt[k] = pt[u] + 1, num[k] = num[u];
                    } else if (newCost == cost[k]) {
                        if (newHappiness > total[k]) {
                            pre[k] = u, total[k] = newHappiness;
                            pt[k] = pt[u] + 1;
                        } else if (newHappiness == total[k] && pt[u] + 1 < pt[k]) {
                            pre[k] = u;
                            pt[k] = pt[u] + 1;
                        }
                        num[k] += num[u];
                    }
                }
        }

        cout << num[end] << ' ' << cost[end] << ' ' << total[end] << ' ' << total[end] / pt[end] << '\n';
        outputPath(pre, end);

        delete[] isVisited;
        delete[] cost, pre, total;
        delete[] pt, num;
    }

  private:
    void outputPath(int *pre, int city)
    {
        if (city != start) outputPath(pre, pre[city]);
        cout << (city != start ? "->" : "") << toString[city];
    }
};

int main(void)
{
    Solution s;
    s.dijkstra();
    return 0;
}
