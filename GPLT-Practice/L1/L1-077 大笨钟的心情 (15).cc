#include <bits/stdc++.h>

static constexpr int HOURS = 24;
static constexpr int THRESHOLD = 50;

int main(void) {
    int emotions[HOURS];
    for (size_t i = 0; i < HOURS; ++i) std::cin >> emotions[i];

    int hr;
    while (true) {
        std::cin >> hr;
        if (hr < 0 || hr >= HOURS) break;
        std::cout << emotions[hr] << ' ';
        std::cout << (emotions[hr] > THRESHOLD ? "Yes" : "No") << '\n';
    }

    return 0;
}
