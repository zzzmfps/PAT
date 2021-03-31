#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 0x3f3f3f3f;

class ClockIn {
private:
    vector<vector<int>> map;

public:
    ClockIn() {
        int n, m;
        cin >> n >> m;
        this->map = vector<vector<int>>(1 + n, vector<int>(1 + n, INF));
        for (int i = 0; i <= n; ++i) this->map[i][i] = 0;
        while (m--) {
            int x, y, dist;
            cin >> x >> y >> dist;
            this->map[x][y] = this->map[y][x] = dist;
        }
    }

    void checkGuidance() const {
        int k, count = 0, index = -1, cost = INF;
        cin >> k;
        for (int i = 1; i <= k; ++i) {
            int n, tmpCost = 0, prev = 0;
            cin >> n;
            if (this->map.size() != 1 + n) {
                // not clock in every place only once
                cin.ignore(INF, '\n');
                continue;
            }

            vector<int> order(1 + n);
            while (n--) cin >> order[n];

            unordered_set<int> visited;
            for (auto &&place : order) {
                if (INF == this->map[prev][place]) {
                    // unreached
                    visited.clear();
                    break;
                }
                tmpCost += this->map[prev][place];
                prev = place;
                visited.insert(place);
            }
            if (this->map.size() != visited.size()) continue;
            ++count;
            if (tmpCost < cost) index = i, cost = tmpCost;
        }
        cout << count << '\n' << index << ' ' << cost;
    }
};

int main(int argc, char const *argv[]) {
    ClockIn ci = ClockIn();
    ci.checkGuidance();
    return 0;
}
