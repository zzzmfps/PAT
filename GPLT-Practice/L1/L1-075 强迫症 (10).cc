#include <bits/stdc++.h>

int main(void) {
    int date;
    std::cin >> date;
    int year = date / 100, month = date % 100;

    if (year < 100) std::cout << (year < 22 ? 20 : 19) << (year > 9 ? "" : "0");
    std::cout << year << '-' << (month > 9 ? "" : "0") << month;

    return 0;
}
