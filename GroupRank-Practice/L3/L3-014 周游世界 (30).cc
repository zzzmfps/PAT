#include <bits/stdc++.h>

static constexpr int INDEX_LIMIT = 10000;

class Travel {
private:
    std::unordered_map<int, std::unordered_map<int, int>> graph;

public:
    Travel() {
        int n;
        std::cin >> n;
        for (int i = 1, j, k, l; i <= n; ++i) {
            std::cin >> j >> k;
            while (--j) {
                std::cin >> l;
                this->graph[k][l] = this->graph[l][k] = i;
                k = l;
            }
        }
    }

    void process() {
        int i, j, k;
        std::cin >> i;
        while (i--) {
            std::cin >> j >> k;
            auto res = this->bfs(j, k);
            this->printResult(res);
        }
    }

private:
    std::vector<int> bfs(int start, int end) {
        std::queue<int> q;
        std::unordered_set<int> visited;
        std::vector<int> pres[INDEX_LIMIT] = {};

        q.push(start);
        visited.insert(start);
        while (!q.empty()) {
            std::unordered_set<int> thisTurn;
            for (int i = q.size(); i > 0; --i) {
                int x = q.front();
                q.pop();
                for (auto &&p : this->graph[x]) {
                    if (visited.find(p.first) != visited.end()) continue;
                    pres[p.first].push_back(x);
                    thisTurn.insert(p.first);
                }
            }
            if (thisTurn.find(end) != thisTurn.end()) break;
            for (auto &&st : thisTurn) q.push(st);
            visited.insert(thisTurn.begin(), thisTurn.end());
        }

        std::vector<int> path, tmp = {end};
        int minTransfer = INDEX_LIMIT;

        auto dfs = [&](auto &&self, int st, int transfer) {
            if (st == start) {
                if (transfer < minTransfer) minTransfer = transfer, path = tmp;
                return;
            }
            for (auto &&pre : pres[st]) {
                bool newTransfer = false;
                if (tmp.size() > 1) {
                    int x = tmp[tmp.size() - 2];
                    newTransfer = (this->graph[x][st] != this->graph[st][pre]);
                }
                tmp.push_back(pre);
                self(self, pre, transfer + newTransfer);
                tmp.pop_back();
            }
        };
        dfs(dfs, end, 0);
        return std::vector<int>(path.rbegin(), path.rend());
    }

    void printResult(const std::vector<int> res) {
        if (res.empty()) {
            std::cout << "Sorry, no line is available.\n";
            return;
        }
        std::cout << res.size() - 1 << '\n';
        for (int i = 1; i < res.size(); ++i) {
            int x = res[i - 1], company = this->graph[x][res[i]];
            std::cout << "Go by the line of company #" << company;
            std::cout << " from " << std::setw(4) << std::setfill('0') << x << " to ";
            while (i + 1 < res.size()) {
                int y = res[i], z = res[i + 1];
                if (company != this->graph[y][z]) break;
                ++i;
            }
            std::cout << std::setw(4) << std::setfill('0') << res[i] << ".\n";
        }
    }
};

int main(void) {
    Travel t;
    t.process();
    return 0;
}
