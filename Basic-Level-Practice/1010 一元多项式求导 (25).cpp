#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    int a, b, is_start = true;
    while (cin >> a >> b) {
        if (!is_start && b != 0) cout << ' ';
        if (b == 0) {
            if (is_start) {
                cout << "0 0";
                is_start = false;
            }
        } else {
            cout << a * b << ' ' << b - 1;
            is_start = false;
        }
    }
    system("pause");
    return 0;
}
