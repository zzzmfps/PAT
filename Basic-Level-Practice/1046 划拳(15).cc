#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    int count, cnt_a = 0, cnt_b = 0;
    int a1, a2, b1, b2;
    cin >> count;
    while (count--) {
        cin >> a1 >> a2 >> b1 >> b2;
        int tmp = a1 + b1;
        if (a2 == tmp && b2 != tmp)
            ++cnt_b;
        else if (b2 == tmp && a2 != tmp)
            ++cnt_a;
    }
    cout << cnt_a << ' ' << cnt_b;
    system("pause");
    return 0;
}
