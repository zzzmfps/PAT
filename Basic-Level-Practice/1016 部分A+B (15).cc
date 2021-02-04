#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    string a, b;
    char da, db;
    cin >> a >> da >> b >> db;
    int ia = da - '0', ib = db - '0', cntA = 0, cntB = 0;
    for (auto ch : a)
        if (ch == da) cntA = cntA * 10 + ia;
    for (auto ch : b)
        if (ch == db) cntB = cntB * 10 + ib;
    cout << cntA + cntB;
    system("pause");
    return 0;
}
