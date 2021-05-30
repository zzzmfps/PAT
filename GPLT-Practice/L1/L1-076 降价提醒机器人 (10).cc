#include <bits/stdc++.h>

int main(void) {
    int n, m;
    std::cin >> n >> m;
    while (n--) {
        double price;
        std::cin >> price;
        if (price < m) std::cout << "On Sale! " << std::fixed << std::setprecision(1) << price << '\n';
    }
    return 0;
}
