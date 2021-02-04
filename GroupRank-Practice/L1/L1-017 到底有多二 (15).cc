#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string num;
    getline(cin, num);
    double ratio = 0.0, fac = 1.0;
    if (num[0] == '-') fac += 0.5;
    if (!((num.back() - 48) & 1)) fac *= 2.0;
    for (auto c : num)
        if (c == '2') ratio += 1.0;
    ratio *= 100.0 * fac / (num.size() - (num[0] == '-' ? 1.0 : 0.0));
    cout << fixed << setprecision(2) << ratio << '%';
    return 0;
}
