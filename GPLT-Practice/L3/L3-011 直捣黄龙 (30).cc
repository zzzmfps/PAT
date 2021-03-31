#include <bits/stdc++.h>
using namespace std;

static constexpr int INF = 0x3f3f3f3f;

class Attack {
private:
    int n, k, s, t;
    unordered_map<string, int> toInt;
    vector<string> toStr;

    vector<int> nums;
    vector<vector<int>> graph;

    unordered_map<int, vector<int>> pres;
    vector<int> path;
    int count = 0, maxKill = 0;

public:
    Attack() {
        cin >> this->n >> this->k;
        this->toStr.reserve(this->n);
        this->s = this->getCity();
        this->t = this->getCity();

        this->nums.resize(this->n);
        for (int i = 1, j, k; i < this->n; ++i) {
            j = this->getCity();
            cin >> k;
            this->nums[j] = k;
        }

        this->graph = vector<vector<int>>(this->n, vector<int>(this->n, INF));
        for (int i = 0, j, k, l; i < this->k; ++i) {
            j = this->getCity(), k = this->getCity();
            cin >> l;
            this->graph[j][k] = this->graph[k][j] = l;
        }
    }

    void process() {
        vector<bool> visited(this->n);
        vector<int> dist(this->n, INF);
        dist[this->s] = 0;

        for (int i = 0; i < this->n; ++i) {
            int u = -1, minDist = INF;
            for (int j = 0; j < this->n; ++j) {
                if (visited[j]) continue;
                if (dist[j] < minDist) u = j, minDist = dist[j];
            }
            visited[u] = true;
            for (int k = 0; k < this->n; ++k) {
                if (visited[k]) continue;
                if (INF == this->graph[u][k]) continue;
                int newDist = dist[u] + this->graph[u][k];
                if (newDist < dist[k]) {
                    dist[k] = newDist;
                    pres[k].clear();
                }
                if (newDist == dist[k]) pres[k].push_back(u);
            }
        }

        vector<int> tmpPath;
        this->dfs(tmpPath, this->t);

        for (int i = this->path.size() - 1; i > -1; --i) cout << this->toStr[this->path[i]] << (i ? "->" : "");
        cout << '\n' << this->count << ' ';
        int finalDist = 0;
        for (int i = 1; i < this->path.size(); ++i) finalDist += this->graph[this->path[i - 1]][this->path[i]];
        cout << finalDist << ' ' << this->maxKill << '\n';
    }

private:
    void dfs(vector<int> &tmpPath, int i) {
        if (i == this->s) {
            ++count;
            tmpPath.push_back(this->s);
            if (tmpPath.size() < this->path.size()) return;
            int kills = 0;
            for (auto &&p : tmpPath) kills += this->nums[p];
            if (tmpPath.size() > this->path.size() || kills > this->maxKill) {
                this->path = tmpPath;
                this->maxKill = kills;
            }
            tmpPath.pop_back();
        }
        tmpPath.push_back(i);
        for (auto &&p : this->pres[i]) dfs(tmpPath, p);
        tmpPath.pop_back();
    }

    int getCity() {
        string city;
        cin >> city;
        if (this->toInt.find(city) == this->toInt.end()) {
            this->toInt[city] = this->toStr.size();
            this->toStr.push_back(city);
        }
        return this->toInt[city];
    }
};

int main(void) {
    Attack atk;
    atk.process();
    return 0;
}
