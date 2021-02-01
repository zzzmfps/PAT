#include <bits/stdc++.h>
using namespace std;

static constexpr int INF = 0x3f3f3f3f;

class RankMap {
private:
    int n, m, start, dest;
    pair<int, int> **costs; // length, time

    vector<int> tmp1, tmp2;
    vector<vector<int>> path;

public:
    RankMap() {
        cin >> n >> m;
        costs = new pair<int, int> *[n];
        for (int i = 0; i < n; ++i) {
            costs[i] = new pair<int, int>[n];
            fill_n(costs[i], n, make_pair(INF, INF));
            costs[i][i].first = costs[i][i].second = 0;
        }
        while (m--) {
            int v1, v2, isOneWay, length, time;
            cin >> v1 >> v2 >> isOneWay;
            cin >> costs[v1][v2].first >> costs[v1][v2].second;
            if (!isOneWay) costs[v2][v1] = costs[v1][v2];
        }
        cin >> start >> dest;
    }

    ~RankMap() {
        for (int i = 0; i < n; ++i) delete[] costs[i];
        delete[] costs;
    }

    void process() {
        dijkstra(2, 1);
        dijkstra(1, 0);
        int cost1 = getCost(path[0], 2);
        int cost2 = getCost(path[1], 1);

        auto isEqual = [](const vector<int> &v1, const vector<int> &v2) {
            if (v1.size() != v2.size()) return false;
            for (int i = 0; i < v1.size(); ++i)
                if (v1[i] != v2[i]) return false;
            return true;
        };
        if (isEqual(path[0], path[1])) {
            cout << "Time = " << cost1 << "; Distance = " << cost2 << ": ";
            rprint(path[0], " => ");
        } else {
            cout << "Time = " << cost1 << ": ";
            rprint(path[0], " => ");
            cout << "Distance = " << cost2 << ": ";
            rprint(path[1], " => ");
        }
    }

private:
    void dijkstra(int type1, int type2) {
        vector<int> *pre = new vector<int>[n] {};
        bool *isVisited = new bool[n]{};
        int *metrics = new int[n];
        fill_n(metrics, n, INF), metrics[start] = 0;

        for (int i = 0; i < n; ++i) {
            int u = -1, minCost = INF;
            for (int j = 0; j < n; ++j)
                if (!isVisited[j] && metrics[j] < minCost) u = j, minCost = metrics[j];
            isVisited[u] = true;
            for (int k = 0; k < n; ++k) {
                if (isVisited[k]) continue;
                int newCost = metrics[u] + (1 == type1 ? costs[u][k].first : costs[u][k].second);
                if (newCost < metrics[k]) {
                    pre[k].clear();
                    metrics[k] = newCost;
                }
                if (newCost == metrics[k]) pre[k].push_back(u);
            }
        }
        dfs(pre, dest, type2);
        path.emplace_back(tmp2);
        tmp2.clear();

        delete[] metrics;
        delete[] isVisited;
        delete[] pre;
    }

    void dfs(const vector<int> *pre, int node, int type2) {
        tmp1.push_back(node);
        if (start == node) {
            if (tmp2.empty() || getCost(tmp1, type2) < getCost(tmp2, type2)) tmp2 = tmp1;
            tmp1.pop_back();
            return;
        }
        for (auto n : pre[node]) dfs(pre, n, type2);
        tmp1.pop_back();
    }

    int getCost(const vector<int> &res, int type2) const {
        if (0 == type2) return res.size();
        int dist = 0;
        for (int i = res.size() - 1; i > 0; --i) {
            auto &p = costs[res[i]][res[i - 1]];
            dist += (1 == type2 ? p.first : p.second);
        }
        return dist;
    }

    void rprint(const vector<int> &res, const string &delim, const string &end = "\n") {
        if (!res.empty()) cout << res.back();
        for (int i = res.size() - 2; i > -1; --i) cout << delim << res[i];
        cout << end;
    }
};

int main(void) {
    RankMap rm;
    rm.process();
    return 0;
}
