#include <iostream>
#include <queue>
#include <utility>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    int delta[3][6] = {{-1, 1, 0, 0, 0, 0}, {0, 0, -1, 1, 0, 0}, {0, 0, 0, 0, -1, 1}};
    struct Index {
        int x, y, z;
        Index(int a, int b, int c) : x(a), y(b), z(c) {}
    };
    int m, n, l, t;
    pair<int, bool> ***slices;

  public:
    Solution()
    {
        cin >> m >> n >> l >> t;
        slices = new pair<int, bool> **[l];
        for (int i = 0; i < l; ++i) {
            slices[i] = new pair<int, bool> *[m];
            for (int j = 0; j < m; j++) {
                slices[i][j] = new pair<int, bool>[n] {};
                for (int k = 0; k < n; ++k) cin >> slices[i][j][k].first;
            }
        }
    }

    int getVolume()
    {
        int count = 0;
        for (int i = 0; i < l; ++i)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < n; ++k)
                    if (check(i, j, k)) count += bfs(i, j, k);
        return count;
    }

  private:
    int bfs(int i, int j, int k)
    {
        Index point(i, j, k);
        queue<Index> tmp;
        tmp.push(point);
        slices[i][j][k].second = true;

        int ret = 0;
        while (!tmp.empty()) {
            auto &idx = tmp.front();
            ++ret;
            for (int d = 0; d < 6; ++d) {
                point.x = idx.x + delta[0][d], point.y = idx.y + delta[1][d], point.z = idx.z + delta[2][d];
                if (check(point.x, point.y, point.z)) {
                    tmp.push(point);
                    slices[point.x][point.y][point.z].second = true;
                }
            }
            tmp.pop();
        }
        return ret < t ? 0 : ret;
    }

    bool check(int i, int j, int k) const
    {
        if (i >= l || i < 0 || j >= m || j < 0 || k >= n || k < 0) return false;
        auto &p = slices[i][j][k];
        if (p.first == 0 || p.second) return false;
        return true;
    }
};

int main(void)
{
    Solution s;
    cout << s.getVolume();
    return 0;
}
