#include <bits/stdc++.h>

int main(void) {
    unsigned n, level;
    unsigned _min = 1000000, n1 = 0, _max = 0, n2 = 0;
    std::cin >> n;
    while (n--) {
        std::cin >> level;
        if (level < _min) _min = level, n1 = 0;
        if (level > _max) _max = level, n2 = 0;
        if (level == _min) ++n1;
        if (level == _max) ++n2;
    }
    std::cout << _min << ' ' << n1 << '\n' << _max << ' ' << n2;
    return 0;
}
