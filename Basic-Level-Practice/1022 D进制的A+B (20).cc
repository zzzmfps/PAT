#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    int num1, num2, base;
    cin >> num1 >> num2 >> base;
    num1 += num2;
    string res = "";
    while (num1) {
        res += to_string(num1 % base);
        num1 /= base;
    }
    res.empty() ? cout << 0 : cout << string(res.crbegin(), res.crend());
    system("pause");
    return 0;
}
