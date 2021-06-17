#include <bits/stdc++.h>

static constexpr double SQRT2 = 1.414213562373;
static constexpr std::pair<int, int> DELTA[] = {{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};

struct Point {
    int x, y;
    Point() {}
    Point(int x_, int y_) : x(x_), y(y_) {}

    bool check(int lu_x, int lu_y, int rb_x, int rb_y) {
        return x >= lu_x && y >= lu_y && x < rb_x && y < rb_y;
    }
    int shape(const Point &p1, const Point &p2) {
        int t = (y - p1.y) * (x - p2.x) - (y - p2.y) * (x - p1.x);
        if (0 == t) return 0;
        return (t > 0 ? 1 : -1);
    }
    Point move(const std::pair<int, int> &delta) {
        return Point(x + delta.first, y + delta.second);
    }

    friend bool operator!=(const Point &p1, const Point &p2) {
        return p1.x != p2.x || p1.y != p2.y;
    };
};

int main(void) {
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> mat(n);
    for (size_t i = 0; i < n; ++i) {
        mat[i].resize(m);
        for (size_t j = 0; j < m; ++j) std::cin >> mat[i][j];
    }

    Point p1, p2;
    std::cin >> p1.x >> p1.y >> p2.x >> p2.y;

    auto findWayToEnd = [&](int shape) -> double {
        bool **visited = new bool *[n];
        for (size_t i = 0; i < n; ++i) visited[i] = new bool[m]{};
        double **bfs = new double *[n]; // accumulate score
        for (size_t i = 0; i < n; ++i) {
            bfs[i] = new double[m];
            std::fill_n(bfs[i], m, std::numeric_limits<double>::max());
        }
        bfs[p1.y][p1.x] = mat[p1.y][p1.x];

        std::queue<Point> q;
        q.push(p1);
        while (!q.empty()) {
            auto c = q.front();
            visited[c.y][c.x] = false; // need update if find a better path
            q.pop();

            for (size_t i = 0; i < 8; ++i) {
                Point np = c.move(DELTA[i]);
                if (!np.check(0, 0, m, n)) continue;
                if (np != p2 && shape != np.shape(p1, p2)) continue;

                double newScore = bfs[c.y][c.x] + mat[np.y][np.x];
                newScore += (i & 1 ? 0 : (SQRT2 - 1) * (mat[c.y][c.x] + mat[np.y][np.x]));
                if (bfs[np.y][np.x] > newScore) { // find a new or better path
                    bfs[np.y][np.x] = newScore;
                    if (!visited[np.y][np.x]) {
                        visited[np.y][np.x] = true;
                        q.push(np);
                    }
                }
            }
        }

        double res = bfs[p2.y][p2.x];
        for (size_t i = 0; i < n; ++i) delete bfs[i];
        delete[] bfs;
        for (size_t i = 0; i < n; ++i) delete visited[i];
        delete[] visited;

        return res;
    };

    double curve1 = findWayToEnd(1);
    double curve2 = findWayToEnd(-1);
    double score = curve1 + curve2 - mat[p1.y][p1.x] - mat[p2.y][p2.x];
    std::cout << std::fixed << std::setprecision(2) << score;

    return 0;
}
