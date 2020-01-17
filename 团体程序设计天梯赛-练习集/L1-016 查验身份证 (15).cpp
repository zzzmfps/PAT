#include <iostream>
#include <string>
#include <vector>
using namespace std;

static const int weights[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
static const char checks[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main(void)
{
    int n;
    (cin >> n).get();
    vector<string> ids(n);
    for (int i = 0; i < n; ++i) getline(cin, ids[i]);
    for (int i = n - 1; i > -1; --i) {
        int chk = 0;
        for (int j = 0; j < 17; ++j) chk += weights[j] * (ids[i][j] == 'X' ? 10 : ids[i][j] - 48);
        if (ids[i].back() == checks[chk % 11]) ids.erase(ids.begin() + i);
    }
    if (ids.empty()) {
        cout << "All passed";
    } else {
        for (auto &s : ids) cout << s << '\n';
    }
    return 0;
}
