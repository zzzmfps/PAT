#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class Solution
{
private:
    int m, n, l, t;
    vector<vector<vector<int>>> block;

public:
    Solution()
    {
        cin >> m >> n >> l >> t;
        block.resize(l);
        for (int i = 0; i < l; ++i) {
            block[i].resize(m);
            for (int j = 0; j < m; ++j) {
                block[i][j].resize(n);
                for (int k = 0; k < n; ++k) {
                    cin >> block[i][j][k];
                }
            }
        }
    }

    int accumulate()
    {
        int acc = 0;
        vector<vector<vector<bool>>> visited(l, vector<vector<bool>>(m, vector<bool>(n)));
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (!visited[i][j][k]) {
                        acc += getCurrentVolume(i, j, k, visited);
                    }
                }
            }
        }
        return acc;
    }

private:
    int getCurrentVolume(int i, int j, int k, vector<vector<vector<bool>>> &visited)
    {
        visited[i][j][k] = true;
        if (block[i][j][k] == 0) return 0;
        int thisPart = 1;
        vector<tuple<int, int, int>> flood = {{i, j, k}};
        auto extendOne = [&](int x, int y, int z) {
            if (!visited[x][y][z] && block[x][y][z]) {
                flood.emplace_back(x, y, z);
                visited[x][y][z] = true;
                thisPart += 1;
            }
        };
        while (!flood.empty()) {
            auto p = flood.back();
            int x = get<0>(p), y = get<1>(p), z = get<2>(p);
            flood.pop_back();
            if (x > 0) extendOne(x - 1, y, z);
            if (x + 1 < l) extendOne(x + 1, y, z);
            if (y > 0) extendOne(x, y - 1, z);
            if (y + 1 < m) extendOne(x, y + 1, z);
            if (z > 0) extendOne(x, y, z - 1);
            if (z + 1 < n) extendOne(x, y, z + 1);
        }
        return (thisPart >= t ? thisPart : 0);
    }
};

int main(void)
{
    Solution s;
    cout << s.accumulate();
    return 0;
}
