#include <iostream>
using namespace std;

int main(void) {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        int x = 0;
        cin.get();
        for (int j = 0; j < m; ++j) x = ('n' == cin.get()) + (x << 1);
        cout << 1 + x << '\n';
    }
    return 0;
}
