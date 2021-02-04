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
    const int LIMIT = 0x3FFFFFFF;
    int n, m, c1, c2;
    int *teams, **roads, *lens;
    bool *isVisited;

  public:
    Solution()
    {
        cin >> n >> m >> c1 >> c2;

        teams = new int[n];
        for (int i = 0; i < n; ++i) cin >> teams[i];

        roads = new int *[n];
        for (int i = 0; i < n; ++i) {
            roads[i] = new int[n];
            fill(roads[i], roads[i] + n, LIMIT);
        }
        for (int i = 0, t1, t2, l; i < m; ++i) {
            cin >> t1 >> t2 >> l;
            roads[t1][t2] = roads[t2][t1] = l;
        }

        lens = new int[n];
        fill(lens, lens + n, LIMIT);
        lens[c1] = 0;

        isVisited = new bool[n]{};
    }

    void dijkstra()
    {
        int *count = new int[n]{}, *rt = new int[n]{};
        count[c1] = 1, rt[c1] = teams[c1];

        for (int i = 0; i < n; ++i) {
            int u = -1, minLen = LIMIT;
            for (int j = 0; j < n; ++j)
                if (!isVisited[j] && lens[j] < minLen) u = j, minLen = lens[j];
            isVisited[u] = true;
            for (int k = 0; k < n; ++k)
                if (!isVisited[k] && roads[u][k] != LIMIT) {
                    int newLen = lens[u] + roads[u][k], newTeams = teams[k] + rt[u];
                    if (newLen < lens[k]) {
                        lens[k] = newLen;
                        count[k] = count[u];
                        rt[k] = newTeams;
                    } else if (newLen == lens[k]) {
                        count[k] += count[u];
                        if (newTeams > rt[k]) rt[k] = newTeams;
                    }
                }
        }

        cout << count[c2] << ' ' << rt[c2];
    }
};

int main(void)
{
    Solution s;
    s.dijkstra();
    return 0;
}
