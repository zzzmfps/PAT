#include <iomanip>
#include <iostream>
using namespace std;

static const double rf = 1.09;
static const double rm = 1.0 / rf;

int main(void)
{
    int n;
    cin >> n;
    while (n--) {
        char gender;
        double height;
        cin >> gender >> height;
        cout << fixed << setprecision(2) << (gender == 'F' ? rf : rm) * height << '\n';
    }
    return 0;
}
