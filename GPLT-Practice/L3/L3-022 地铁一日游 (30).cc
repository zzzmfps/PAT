#include <bits/stdc++.h>

/* *** 究竟是哪个智障出的题？！
 * 1，从一个站点(a)开始，每次出站(b)拍照后从同一站点(b)再次进站进行下一轮
 * 2，计费距离为“达到”，而不是“超过”：k=5 时，距离 0~4 价格相同，5~9 相同，以此类推
 * 3，由于存在起步价，因此起点价格为0，其它站点为 起步价+x
 * 4，“两个站之间可能有多条直接连接的线路”：相邻站点
 */

static constexpr size_t MAX = 0x3fffffff;

struct Station {
    bool end = false;
    std::unordered_map<size_t, size_t> connected;
};

size_t *dijkstra(const std::vector<Station> &graph, size_t start) {
    size_t size = graph.size();

    bool *visited = new bool[size]{};
    size_t *dists = new size_t[size];
    std::fill_n(dists, size, MAX);
    dists[start] = 0;

    for (size_t i = 1; i < size; ++i) {
        size_t u = MAX, minDist = MAX;
        for (size_t j = 1; j < size; ++j) {
            if (visited[j]) continue;
            if (dists[j] < minDist) u = j, minDist = dists[j];
        }
        if (MAX == u) break; // not all connected
        visited[u] = true;
        for (auto &&k : graph[u].connected) {
            if (visited[k.first]) continue;
            size_t newDist = dists[u] + k.second;
            if (newDist < dists[k.first]) dists[k.first] = newDist;
        }
    }
    delete[] visited;
    return dists;
}

int main(void) {
    size_t n, m, k, q;
    std::cin >> n >> m >> k;

    std::vector<Station> graph(1 + n);
    for (size_t i = 1, st1, dist, st2; i <= m; ++i) { // input
        std::cin >> st1;
        graph[st1].end = true;
        while ('\n' != std::cin.peek()) {
            std::cin >> dist >> st2;
            auto &r1 = graph[st1].connected[st2], &r2 = graph[st2].connected[st1];
            if (0 == r1 || r1 > dist) r1 = r2 = dist; // multi-connection
            st1 = st2;
        }
        graph[st1].end = true;
    }

    bool **res = new bool *[1 + n];
    for (size_t i = 1; i <= n; ++i) { // stations with ONE turn
        res[i] = new bool[1 + n]{};
        size_t *dists = dijkstra(graph, i);

        std::unordered_map<size_t, std::vector<size_t>> costs;
        for (size_t j = 1; j <= n; ++j) {
            if (MAX == dists[j]) continue;
            auto c = 2 * (dists[j] > 0) + dists[j] / k;
            if (costs.find(c) == costs.end() || costs[c][0] < dists[j]) {
                costs[c].clear();
                costs[c].push_back(dists[j]);
            }
            if (costs[c][0] == dists[j]) costs[c].push_back(j);
        }
        for (auto &&c : costs)
            for (size_t j = 1; j < c.second.size(); ++j) res[i][c.second[j]] = true;
        for (size_t j = 1; j <= n; ++j)
            if (i != j && graph[j].end && MAX != dists[j]) res[i][j] = true;
        delete[] dists;
    }

    for (size_t i = 1; i <= n; ++i) { // take a photo and continue (re-calculate)
        bool *visited = new bool[1 + n]{};
        visited[i] = true;
        std::queue<size_t> queue;
        queue.push(i);
        while (!queue.empty()) {
            auto cur = queue.front();
            queue.pop();
            for (size_t j = 1; j <= n; ++j) {
                if (!visited[j] && res[cur][j]) {
                    res[i][j] = res[cur][j];
                    visited[j] = true;
                    queue.push(j);
                }
            }
        }
        delete[] visited;
    }

    std::cin >> q;
    for (size_t i = 0, xi; i < q; ++i) { // output
        std::cin >> xi;
        for (size_t j = 1, count = 0; j <= n; ++j) {
            if (!res[xi][j]) continue;
            if (count++) std::cout << ' ';
            std::cout << j;
        }
        std::cout << '\n';
    }

    for (size_t i = 1; i <= n; ++i) delete[] res[i];
    delete[] res;
    return 0;
}
