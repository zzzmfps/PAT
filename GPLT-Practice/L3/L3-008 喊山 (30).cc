#include <bits/stdc++.h>
using namespace std;

static constexpr int INF = 0x3f3f3f3f;

class ShoutMountain {
private:
    int n, m, k;
    vector<int> *connected;

public:
    ShoutMountain() {
        cin >> n >> m >> k;
        connected = new vector<int>[1 + n];
        for (int i = 0, x, y; i < m; ++i) {
            cin >> x >> y;
            connected[x].push_back(y);
            connected[y].push_back(x);
        }
    }
    ~ShoutMountain() {
        delete[] connected;
    }

    void process() {
        for (int i = 0, last = INF, x; i < k; ++i) {
            cin >> x;
            queue<int> q;
            bool *visited = new bool[1 + n]{};
            q.push(x), visited[x] = true;

            while (!q.empty()) {
                int tmpLast = INF;
                for (int i = q.size(); i > 0; --i) {
                    int cur = q.front();
                    for (auto &&v : connected[cur]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                            tmpLast = min(tmpLast, v);
                        }
                    }
                    q.pop();
                }
                if (INF != tmpLast) last = tmpLast;
            }
            delete[] visited;

            cout << (INF == last ? 0 : last) << '\n';
            last = INF;
        }
    }
};

int main(void) {
    ShoutMountain sm;
    sm.process();
    return 0;
}
