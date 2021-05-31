#include <bits/stdc++.h>

using Vector = std::vector<size_t>;
using Matrix = std::vector<Vector>;

Vector popNextLink(Matrix &links, size_t root) {
    Vector ret = {root};
    while (!links[root].empty()) {
        ret.push_back(links[root].back());
        root = ret.back();
    }
    for (auto i = std::next(ret.rbegin()); i != ret.rend(); ++i) {
        links[*i].pop_back();
        if (!links[*i].empty()) break;
    }
    return ret;
}

int main(void) {
    size_t n;
    std::cin >> n;

    Matrix links(n);
    bool *isNotRoot = new bool[n]{};

    for (size_t i = 0, k; i < n; ++i) {
        std::cin >> k;
        links[i].resize(k);
        for (size_t j = 0; j < k; ++j) {
            std::cin >> links[i][j];
            isNotRoot[links[i][j]] = true;
        }
        std::sort(links[i].rbegin(), links[i].rend());
    }

    size_t root = 0;
    while (isNotRoot[root]) ++root;
    delete[] isNotRoot;

    Vector res = {root};
    while (!links[root].empty()) {
        auto _next = popNextLink(links, root);
        if (_next.size() > res.size()) res = _next;
    }

    std::cout << res.size() << '\n' << res[0];
    for (size_t i = 1; i < res.size(); ++i) std::cout << ' ' << res[i];

    return 0;
}
