#include <bits/stdc++.h>
using namespace std;

using Edge = pair<int, int>; // capacity, flow
using Network = unordered_map<int, unordered_map<int, Edge>>;

static constexpr int INF = 0x3f3f3f3f;

template <typename K, typename V>
static bool contains(const unordered_map<K, V> &umap, const K &key) {
#if __cplusplus > 201703L
    return umap.contains(key); // C++20
#else
    return umap.find(key) != umap.end();
#endif
}

class UniversalTravel {
private:
    int n, m;         // num of nodes, edges
    int s = 0, t = 1; // source, sink
    Network graph;    // structure of flow network

public:
    UniversalTravel() {
        unordered_map<string, int> names;
        int count = 0;

        string from, to;
        int val;
        cin >> from >> to >> val;
        names[from] = count++, names[to] = count++; // source: 0, sink: 1

        this->m = val;
        for (int i = val; i > 0; --i) {
            cin >> from >> to >> val;
            if (!contains(names, from)) names[from] = count++;
            if (!contains(names, to)) names[to] = count++;
            int j = names[from], k = names[to];
            this->graph[j][k] = Edge(val, 0);
            if (!contains(this->graph[k], j)) this->graph[k][j] = Edge(0, 0);
        }
        this->n = names.size();
    }

    // Edmonds-Karp algorithm
    void ek();

    // Dinic's algorithm
    void dinic();

    // ISAP algorithm
    void isap();
};

void UniversalTravel::ek() {
    int flow = 0;
    while (true) {
        vector<int> flows(this->n), pres(this->n, -1);
        flows[this->s] = INF;

        queue<int> q;
        q.push(this->s);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto &&p : this->graph[x]) {
                int y = p.first;
                auto &e = p.second;
                if (!flows[y] && e.first > e.second) {
                    pres[y] = x;
                    flows[y] = min(flows[x], e.first - e.second);
                    q.push(y);
                }
            }
            if (flows[this->t]) break; // sink received flow
        }
        if (!flows[this->t]) break; // cannot reach sink

        for (int u = this->t; u != this->s; u = pres[u]) {
            this->graph[pres[u]][u].second += flows[this->t];
            this->graph[u][pres[u]].second -= flows[this->t];
        }
        flow += flows[this->t];
    }
    cout << flow << '\n';
}

void UniversalTravel::dinic() {
    int flow = 0;
    while (true) {
        vector<int> levels(this->n);

        vector<bool> visited(this->n);
        visited[this->s] = true;
        queue<int> q;
        q.push(this->s);
        while (!q.empty()) { // construct level graph
            int x = q.front();
            q.pop();
            for (auto &&p : this->graph[x]) {
                int y = p.first;
                auto &e = p.second;
                if (!visited[y] && e.first > e.second) {
                    visited[y] = true;
                    levels[y] = 1 + levels[x];
                    q.push(y);
                }
            }
        }
        if (!levels[this->t]) break; // cannot reach sink

        vector<int> cur(this->n); // current arc optimize
        auto dfs = [&](auto &&self, int x, int usable) {
            if (x == this->t || 0 == usable) return usable;
            int flow = 0, f;
            for (int i = cur[x], size = this->graph[x].size(); i < size; ++i) {
                const auto &ptr = next(this->graph[x].begin(), i);
                int y = ptr->first;
                if (levels[x] + 1 != levels[y]) continue;
                auto &e = ptr->second;
                if (!(f = self(self, y, min(usable, e.first - e.second)))) continue;
                e.second += f;
                this->graph[y][x].second -= f;
                flow += f;
                if (!(usable -= f)) break; // check if possible to augment other paths
            }
            return flow;
        };
        flow += dfs(dfs, this->s, INF);
    }
    cout << flow << '\n';
}

void UniversalTravel::isap() {
    int flow = 0;
    vector<int> levels(this->n);

    vector<bool> visited(this->n);
    visited[this->t] = true;
    queue<int> q;
    q.push(this->t);     // from sink
    while (!q.empty()) { // construct level graph
        int x = q.front();
        q.pop();
        for (auto &&p : this->graph[x]) {
            int y = p.first;
            auto &e = this->graph[y][x]; // reverse it
            if (!visited[y] && e.first > e.second) {
                visited[y] = true;
                levels[y] = 1 + levels[x];
                q.push(y);
            }
        }
    }

    vector<int> pres(this->n, -1); // connected (last) node
    vector<int> cur(this->n);      // current arc optimize
    vector<int> nums(1 + this->n); // GAP optimize
    for (auto &&l : levels) ++nums[l];
    int x = this->s;
    while (levels[this->s] < this->n) { // while sink reachable
        if (x == this->t) {
            int y = this->t, f = INF;
            while (y != this->s) { // get flow
                auto &e = this->graph[pres[y]][y];
                f = min(f, e.first - e.second);
                y = pres[y];
            }
            y = this->t;
            while (y != this->s) { // augment path
                this->graph[pres[y]][y].second += f;
                this->graph[y][pres[y]].second -= f;
                y = pres[y];
            }
            flow += f;
            x = this->s;
        }

        int ok = false;
        for (int &i = cur[x], size = this->graph[x].size(); i < size; ++i) {
            const auto &ptr = next(this->graph[x].begin(), i);
            int y = ptr->first;
            auto &e = ptr->second;
            if (levels[x] == levels[y] + 1 && e.first > e.second) {
                ok = true;
                pres[y] = x, x = y;
                break;
            }
        }
        if (ok) continue;
        if (!--nums[levels[x]]) break; // meets gap

        int lvl = this->n - 1;
        for (auto &&p : this->graph[x]) {
            auto &e = p.second;
            if (e.first > e.second) lvl = min(lvl, levels[p.first]);
        }
        ++nums[levels[x] = lvl + 1]; // update level graph
        cur[x] = 0;
        if (x != this->s) x = pres[x];
    }
    cout << flow << '\n';
}

int main(void) {
    UniversalTravel ut;
    // ut.ek();
    // ut.dinic();
    ut.isap();
    return 0;
}
