#include <bits/stdc++.h>

int main(void) {
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<size_t>> points(1 + n);
    for (size_t i = 1, k; i <= n; ++i) {
        std::cin >> k;
        points[i] = std::vector<size_t>(1 + k);
        for (size_t j = 1; j <= k; ++j) std::cin >> points[i][j];
    }

    size_t cur = 1;
    std::vector<size_t> saves(1);
    for (size_t i = 0, x, y; i < m; ++i) {
        std::cin >> x >> y;
        if (0 == x) {
            cur = points[cur][y];
        } else if (1 == x) {
            if (y >= saves.size()) saves.resize(1 + y);
            saves[y] = cur;
            std::cout << cur << '\n';
        } else {
            cur = saves[y];
        }
    }
    std::cout << cur << '\n';

    return 0;
}
