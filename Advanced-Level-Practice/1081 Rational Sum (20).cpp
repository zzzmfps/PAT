#include <algorithm>
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
    struct Fraction {
        long long numerator, denominator;
        Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {}
    };

  public:
    Solution()
    {
        Fraction res, tmp;
        int n;
        cin >> n;
        while (n--) {
            cin >> tmp;
            rationalSum(res, tmp);
        }
        cout << res;
    }

  private:
    void rationalSum(Fraction &x, const Fraction &y)
    {
        x.numerator = x.numerator * y.denominator + x.denominator * y.numerator;
        x.denominator *= y.denominator;
        reduction(x);
    }

    void reduction(Fraction &x)
    {
        if (x.numerator == 0) {
            x.denominator = 1;
        } else {
            int g = __gcd(x.numerator, x.denominator);
            x.numerator /= g, x.denominator /= g;
        }
    }

    friend istream &operator>>(istream &is, Fraction &x)
    {
        (is >> x.numerator).get();
        is >> x.denominator;
        if (x.denominator < 0) x.numerator = -x.numerator, x.denominator = -x.denominator;
    }

    friend ostream &operator<<(ostream &os, const Fraction &x)
    {
        int num = abs(x.numerator);
        if (x.numerator < 0) os << '-';
        if (x.denominator == 1) {
            cout << num;
        } else {
            if (num > x.denominator) {
                os << num / x.denominator << ' ';
                num %= x.denominator;
            }
            os << num << '/' << x.denominator;
        }
    }
};

int main(void)
{
    Solution s;
    return 0;
}
