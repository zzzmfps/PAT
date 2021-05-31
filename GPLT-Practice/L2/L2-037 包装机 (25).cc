#include <bits/stdc++.h>

int main(void) {
    size_t n, m, sMax;
    std::cin >> n >> m >> sMax;

    std::vector<std::string> traces;
    for (size_t i = 0; i < n; ++i) {
        traces.resize(1 + traces.size());
        std::cin >> traces.back();
    }
    std::vector<size_t> index(n);

    int k;
    std::string res = "", stack = "";
    while (true) {
        std::cin >> k;
        if (-1 == k) break;

        bool flag1 = (0 == k);
        bool flag2 = (stack.size() == sMax);
        bool flag3 = (index[k - 1] < traces[k - 1].size());

        if (!stack.empty() && (flag1 || (flag2 && flag3))) {
            res += stack.back();
            stack.pop_back();
        }
        if (k && flag3) stack += traces[k - 1][index[k - 1]++];
    }
    std::cout << res;

    return 0;
}
