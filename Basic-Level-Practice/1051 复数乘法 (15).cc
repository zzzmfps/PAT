#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    double r1, p1, r2, p2;

  public:
    Solution() { cin >> r1 >> p1 >> r2 >> p2; }

    void getResult()
    {
        const double eps = 0.000001;
        double real = r1 * r2 * cos(p1 + p2);
        double imag = r1 * r2 * sin(p1 + p2);
        real = abs(real) < 0.01 ? 0.0 : real + eps;
        imag = abs(imag) < 0.01 ? 0.0 : imag + eps;
        cout << fixed << setprecision(2) << real << showpos << imag << 'i';
    }
};

int main(void)
{
    Solution s;
    s.getResult();
    return 0;
}
