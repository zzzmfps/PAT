#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    int row, col;
    char fill;
    cin >> col >> fill;
    row = (col + 1) / 2;
    for (int i = col; i > 0; --i) cout << fill;
    cout << '\n';
    for (int i = row - 2; i > 0; --i) {
        cout << fill;
        for (int j = col - 2; j > 0; --j) cout << ' ';
        cout << fill << '\n';
    }
    for (int i = col; i > 0; --i) cout << fill;
    system("pause");
    return 0;
}
