#include <iomanip>
#include <iostream>
using namespace std;

int main(void) {
    double x, y;
    bool flag;
    cin >> x >> flag >> y;

    double res = x * (flag ? 1.26 : 2.455);
    cout << fixed << setprecision(2) << res << ' ' << (y <= res ? "T_T" : "^_^");
    return 0;
}
