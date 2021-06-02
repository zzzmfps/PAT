#include <bits/stdc++.h>

void getOutput(std::map<std::vector<int>, size_t> &counts, size_t m) {
    std::vector<int> vals(m);
    for (size_t i = 0; i < m; ++i) std::cin >> vals[i];
    ++counts[vals];
}

int main(void) {
    size_t n, m;
    std::cin >> n >> m;

    std::map<std::vector<int>, size_t> counts;
    while (n--) getOutput(counts, m);

    using Pair = std::pair<std::vector<int>, size_t>;
    std::vector<Pair> outs(counts.begin(), counts.end());
    std::sort(outs.begin(), outs.end(), [](const Pair &x, const Pair &y) {
        if (x.second != y.second) return x.second > y.second;
        for (size_t i = 0; i < x.first.size(); ++i)
            if (x.first[i] != y.first[i]) return x.first[i] < y.first[i];
        return false; // dead code
    });

    std::cout << outs.size() << '\n';
    for (auto &&p : outs) {
        std::cout << p.second;
        for (auto &&v : p.first) std::cout << ' ' << v;
        std::cout << '\n';
    }

    return 0;
}
