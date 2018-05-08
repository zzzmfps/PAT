#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    int count;
    cin >> count;
    long long a, b, c;
    for (int i = 1; i <= count; ++i) {
        cin >> a >> b >> c;
        long long tmp = a + b;
        cout << "Case #" << i << ": ";
        if (a < 0 && b < 0 && tmp > a)
            cout << "false\n";
        else if (a > 0 && b > 0 && tmp < a)
            cout << "true\n";
        else
            cout << boolalpha << (tmp > c) << '\n';
    }
    system("pause");
    return 0;
}
