#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
private:
    const int INF = 0x3f3f3f3f;
    int n, m, k, ds;
    vector<vector<int>> graph;

public:
    Solution()
    {
        (cin >> n >> m >> k >> ds).get();
        graph = vector<vector<int>>(n + m + 1, vector<int>(n + m + 1, INF));
        for (int i = 0; i < k; ++i) {
            int p1, p2, dist;
            bool gp1 = false, gp2 = false;
            if (cin.peek() == 'G') cin.get(), gp1 = true;
            (cin >> p1).get();
            p1 += gp1 ? n : 0;
            if (cin.peek() == 'G') cin.get(), gp2 = true;
            (cin >> p2 >> dist).get();
            p2 += gp2 ? n : 0;
            graph[p1][p2] = graph[p2][p1] = dist;
        }
    }

    void distribute()
    {
        int bestIndex = 0;
        pair<double, double> best = {0, INF};
        for (int i = 1; i < m + 1; ++i) {
            vector<int> gi = dijkstra(n + i);
            int _max = *max_element(gi.begin() + 1, gi.begin() + n + 1);
            if (_max > ds) continue;
            int _min = *min_element(gi.begin() + 1, gi.begin() + n + 1);
            int _sum = accumulate(gi.begin() + 1, gi.begin() + n + 1, 0);
            if (_min > best.first || _min == best.first && _sum < best.second) {
                bestIndex = i;
                best.first = _min;
                best.second = _sum;
            }
        }
        if (bestIndex > 0) {
            cout << 'G' << bestIndex << '\n';
            cout << fixed << setprecision(1);
            // sometimes `best.second/n` fails in rounding off, due to precision problem
            cout << best.first << ' ' << best.second / n << '\n';
        } else {
            cout << "No Solution";
        }
    }

private:
    vector<int> dijkstra(int index)
    {
        vector<int> dist(n + m + 1, INF);
        dist[index] = 0;
        vector<bool> visited(n + m + 1);
        for (int i = 1; i < n + m; ++i) {
            int u = -1, minLen = INF;
            for (int j = 1; j < n + m + 1; ++j) { // nearest among those haven't been visited
                if (!visited[j] && dist[j] < minLen) {
                    u = j;
                    minLen = dist[j];
                }
            }
            if (u == -1) break;
            visited[u] = true;
            for (int k = 1; k < n + m + 1; ++k) { // update dist, take u as a bridge
                if (!visited[k]) dist[k] = min(dist[k], minLen + graph[u][k]);
            }
        }
        return dist;
    }
};

int main(void)
{
    Solution s;
    s.distribute();
    return 0;
}
