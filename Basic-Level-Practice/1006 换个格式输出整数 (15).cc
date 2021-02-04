#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

static const string digits = "123456789";

int main(void)
{
    int num, b, s, d;
    cin >> num;
    b = num / 100, s = num / 10 % 10, d = num % 10;
    string res = string(b, 'B');
    res += string(s, 'S');
    res += string(digits.begin(), digits.begin() + d);
    cout << res;
    system("pause");
    return 0;
}
