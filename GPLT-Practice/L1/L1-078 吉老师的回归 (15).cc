#include <bits/stdc++.h>

int main(void) {
    int n, m;
    (std::cin >> n >> m).get();
    std::string str, cur;
    while (n--) {
        std::getline(std::cin, str);
        if (str.find("qiandao") != str.npos || str.find("easy") != str.npos) continue;
        if (0 == m--) cur = str;
    }
    std::cout << (m < 0 ? cur : "Wo AK le");
    return 0;
}
