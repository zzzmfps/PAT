#include <iomanip>
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
    string res1 = "";
    double res2 = 1.0;
    for (int i = 0; i < 3; ++i) {
        double w, t, l;
        cin >> w >> t >> l;
        if (w > t && w > l) {
            res1 += "W ";
            res2 *= w;
        } else if (t > l) {
            res1 += "T ";
            res2 *= t;
        } else {
            res1 += "L ";
            res2 *= l;
        }
    }
    cout << res1 << fixed << setprecision(2) << res2 * 1.3 - 2;
    system("pause");
    return 0;
}
