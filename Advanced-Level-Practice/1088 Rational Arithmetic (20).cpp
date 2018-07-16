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
        Fraction(long long n = 0, long long d = 1) : numerator(n), denominator(d) {}
    };

  public:
    Solution()
    {
        Fraction f1, f2, res;
        cin >> f1 >> f2;
        cout << f1 << " + " << f2 << " = " << rationalSumOrDiff(f1, f2, 1) << '\n';
        cout << f1 << " - " << f2 << " = " << rationalSumOrDiff(f1, f2, -1) << '\n';
        cout << f1 << " * " << f2 << " = " << rationalProdOrQuot(f1, f2, 1) << '\n';
        cout << f1 << " / " << f2 << " = " << rationalProdOrQuot(f1, f2, -1) << '\n';
    }

  private:
    Fraction rationalSumOrDiff(const Fraction &x, const Fraction &y, int signal)
    {
        Fraction z;
        z.numerator = x.numerator * y.denominator + signal * x.denominator * y.numerator;
        z.denominator = x.denominator * y.denominator;
        reduction(z);
        return z;
    }

    Fraction rationalProdOrQuot(const Fraction &x, const Fraction &y, int type)
    {
        Fraction z;
        if (type == 1) {
            z.numerator = x.numerator * y.numerator;
            z.denominator = x.denominator * y.denominator;
        } else {
            z.numerator = x.numerator * y.denominator;
            z.denominator = x.denominator * y.numerator;
        }
        reduction(z);
        return z;
    }

    static void reduction(Fraction &x)
    {
        if (x.denominator < 0) x.numerator = -x.numerator, x.denominator = -x.denominator;
        if (x.numerator == 0) {
            x.denominator = 1;
        } else {
            int g = abs(__gcd(x.numerator, x.denominator));
            x.numerator /= g, x.denominator /= g;
        }
    }

    friend istream &operator>>(istream &is, Fraction &x)
    {
        (is >> x.numerator).get();
        is >> x.denominator;
        reduction(x);
        return is;
    }

    friend ostream &operator<<(ostream &os, const Fraction &x)
    {
        if (x.denominator == 0) {
            os << "Inf";
        } else {
            long long num = abs(x.numerator);
            if (x.numerator < 0) os << "(-";
            if (x.denominator == 1) {
                cout << num;
            } else {
                if (num > x.denominator) {
                    os << num / x.denominator << ' ';
                    num %= x.denominator;
                }
                os << num << '/' << x.denominator;
            }
            if (x.numerator < 0) os << ')';
        }
        return os;
    }
};

int main(void)
{
    Solution s;
    return 0;
}
