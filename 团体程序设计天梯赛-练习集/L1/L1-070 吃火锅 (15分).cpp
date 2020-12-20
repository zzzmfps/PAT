#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

static bool check(int x, int _min, int _max, int _diff) {
    return x < _min || _max - x > _diff;
}

int main(void) {
    string line;
    int begin = 0, count = 0, total = 0;

    while (getline(cin, line)) {
        if ("." == line) break;
        ++total;
        if (line.find("chi1 huo3 guo1") != -1) {
            begin = (0 == begin) ? total : begin;
            ++count;
        }
    }

    cout << total << '\n';
    if (begin != 0) {
        cout << begin << ' ' << count << '\n';
    } else {
        cout << "-_-#";
    }

    return 0;
}
