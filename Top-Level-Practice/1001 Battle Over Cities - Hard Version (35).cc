#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
// could reduce runtime from 650ms to 287ms
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
*/

class Solution
{
private:
    struct Edge
    {
        int start, dest;
        int cost;
        Edge(int s, int d, int c = 0) : start(s), dest(d), cost(c) {}
    };
    struct SortRule
    {
        bool operator() (const Edge &x, const Edge &y) { return x.cost < y.cost; };
    };
    int cities, highways;
    vector<Edge> graph; // connected highways
    vector<Edge> repairs;   // destroyed highways

public:
    Solution()
    {
        cin >> cities >> highways;
        for (int i = 0; i < highways; ++i) {
            int c1, c2, cost, status;
            cin >> c1 >> c2 >> cost >> status;
            if (status) {
                graph.emplace_back(c1, c2);
            } else {
                repairs.emplace_back(c1, c2, cost);
            }
        }
        sort(repairs.begin(), repairs.end(), SortRule());
    }

    bool battleOverCitiesHardVersion()
    {
        if (cities == 1) return 1;
        int maxCost = 0;
        vector<int> ans;
        for (int i = 1; i <= cities; ++i) {
            int *uset = new int[cities + 1];    // union set
            for (int i = 1; i <= cities; ++i) uset[i] = i;
            int clusters = cities - 1;  // divided into how many parts
            for (const auto &e : graph) {   // recheck connections after losing a city
                if (e.start == i || e.dest == i) continue;
                if (findRoot(uset, e.start) != findRoot(uset, e.dest)) {
                    clusters -= 1;	// two clusters are combined
                    join(uset, e.start, e.dest);
                }
            }
            if (clusters == 1) continue;
            int curCost = 0;
            for (const auto &e : repairs) {
                if (i == e.start || i == e.dest) continue;
                if (findRoot(uset, e.start) == findRoot(uset, e.dest)) continue;
                join(uset, e.start, e.dest);
                curCost += e.cost;
                if (--clusters == 1) break;
            }
            if (clusters > 1) curCost = 0x7FFFFFFF;
            if (curCost > maxCost) {
                maxCost = curCost;
                ans.clear();
            }
            if (curCost == maxCost) ans.push_back(i);
        }
        if (ans.empty()) {
            cout << 0;
        } else {
            cout << ans[0];
            for (int i = 1; i < ans.size(); ++i) cout << ' ' << ans[i];
        }
    }

private:
    int findRoot(int *s, int x)
    {
        int tmp = x;
        while (x != s[x]) x = s[x];
        while (x != s[tmp]) {
            int t2 = s[tmp];
            s[tmp] = x;
            tmp = t2;
        }
        return x;
    }

    void join(int *s, int x, int y)
    {
        int xx = findRoot(s, x), yy = findRoot(s, y);
        s[yy] = xx;
    }
};

int main(void)
{
    Solution s;
    s.battleOverCitiesHardVersion();
    return 0;
}
