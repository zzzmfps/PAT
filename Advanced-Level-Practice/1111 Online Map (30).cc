#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
private:
    const int LIMIT = 0x3FFFFFFF;
    int ni, start, target;
    pair<int, int> **omap;

public:
    Solution()
    {
        int ns;
        cin >> ni >> ns;
        omap = new pair<int, int> *[ni];
        for (int i = 0; i < ni; ++i) {
            omap[i] = new pair<int, int>[ni];
            for (int j = 0; j < ni; ++j) omap[i][j] = make_pair(LIMIT, LIMIT);
        }
        while (ns--) {
            int v1, v2, oneWay, length, time;
            cin >> v1 >> v2 >> oneWay >> length >> time;
            omap[v1][v2].first = length, omap[v1][v2].second = time;
            if (!oneWay) omap[v2][v1].first = length, omap[v2][v1].second = time;
        }
        cin >> start >> target;
    }

    ~Solution()
    {
        for (int i = 0; i < ni; ++i) delete[] omap[i];
        delete[] omap;
    }

    void onlineMap()
    {
        vector<int> res1, res2;
        int dist = dijkstra(res1, 1);
        int time = dijkstra(res2, 2);
        if (res1.size() == res2.size() && equal(res1.begin(), res1.end(), res2.begin())) {
            cout << "Distance = " << dist << "; Time = " << time << ": ";
            printPath(res1);
        } else {
            cout << "Distance = " << dist << ": ";
            printPath(res1);
            cout << "\nTime = " << time << ": ";
            printPath(res2);
        }
    }

private:
    int dijkstra(vector<int> &res, int type)
    {
        // when type == 1, shortest -> fastest
        // when type == 2, fastest  -> fewest intersections
        bool *isVisited = new bool[ni] {};
        int *cmp1 = new int[ni], *cmp2 = new int[ni], *pre = new int[ni];
        fill_n(cmp1, ni, LIMIT), fill_n(cmp2, ni, LIMIT);
        cmp1[start] = cmp2[start] = 0, pre[start] = -1;

        for (int i = 0; i < ni; ++i) {
            int u = -1, minCmp1 = LIMIT;
            for (int j = 0; j < ni; ++j)
                if (!isVisited[j] && cmp1[j] < minCmp1) u = j, minCmp1 = cmp1[j];
            isVisited[u] = true;
            for (int k = 0; k < ni; ++k) {
                // p1. cmp1: distance, cmp2: time
                auto p1 = [&](int &x, int &y) { x = cmp1[u] + omap[u][k].first, y = cmp2[u] + omap[u][k].second; };
                // p2. cmp1: time, cmp2: num of intersections
                auto p2 = [&](int &x, int &y) { x = cmp1[u] + omap[u][k].second, y = cmp2[u] + 1; };

                int newCmp1, newCmp2;
                if (type == 1) {
                    p1(newCmp1, newCmp2);
                } else {
                    p2(newCmp1, newCmp2);
                }
                if (newCmp1 < cmp1[k]) {
                    cmp1[k] = newCmp1;
                    cmp2[k] = newCmp2;
                    pre[k] = u;
                } else if (newCmp1 == cmp1[k] && newCmp2 < cmp2[k]) {
                    cmp2[k] = newCmp2;
                    pre[k] = u;
                }
            }
        }

        int ret = cmp1[target];
        delete[] isVisited;
        delete[] cmp1;
        delete[] cmp2;

        for (int i = target; i != -1; i = pre[i]) res.push_back(i);
        delete[] pre;
        reverse(res.begin(), res.end());

        return ret;
    }

    void printPath(const vector<int> &res)
    {
        for (int i = 0; i < res.size(); ++i) {
            if (i > 0) cout << " -> ";
            cout << res[i];
        }
    }
};

int main(void)
{
    Solution s;
    s.onlineMap();
    return 0;
}
