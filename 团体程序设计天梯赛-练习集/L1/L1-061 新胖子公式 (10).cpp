#include <iomanip>
#include <iostream>
using namespace std;

int main(void)
{
    double w, h, r;
    cin >> w >> h;
    r = w / h / h;
    cout << fixed << setprecision(1) << r << '\n' << (r > 25.0 ? "PANG" : "Hai Xing");
    return 0;
}
