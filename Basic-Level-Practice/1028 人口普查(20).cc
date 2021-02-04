#include <iostream>
#include <string>
#include <tuple>
#include <utility>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

auto datecmp = [](int y1, int m1, int d1, int y2, int m2 = 9, int d2 = 6) {
    if (y1 < y2 || y1 == y2 && m1 < m2 || y1 == y2 && m1 == m2 && d1 < d2) return -1;
    if (y1 == y2 && m1 == m2 && d1 == d2) return 0;
    return 1;
};

int main(void)
{
    pair<string, tuple<int, int, int>> r1{"null", make_tuple(2014, 9, 7)};
    pair<string, tuple<int, int, int>> r2{"null", make_tuple(1814, 9, 5)};
    int tmp;
    (cin >> tmp).get();
    int n = tmp;
    while (tmp--) {
        string name;
        int y, m, d;
        getline(cin, name, ' ');
        (cin >> y).get();
        (cin >> m).get();
        (cin >> d).get();
        if (datecmp(y, m, d, 1814) < 0 || datecmp(y, m, d, 2014) > 0) {
            --n;
            continue;
        }
        if (datecmp(y, m, d, get<0>(r1.second), get<1>(r1.second), get<2>(r1.second)) < 0) {
            r1.first = name;
            get<0>(r1.second) = y;
            get<1>(r1.second) = m;
            get<2>(r1.second) = d;
        }
        if (datecmp(y, m, d, get<0>(r2.second), get<1>(r2.second), get<2>(r2.second)) > 0) {
            r2.first = name;
            get<0>(r2.second) = y;
            get<1>(r2.second) = m;
            get<2>(r2.second) = d;
        }
    }
    cout << n;
    if (n) cout << ' ' << r1.first << ' ' << r2.first;
    system("pause");
    return 0;
}
