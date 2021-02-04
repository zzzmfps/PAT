#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> poly[2]; // polynomial A and B, index is exponent
    vector<double> quotient, remainder;

public:
    Solution()
    {
        int n, e, c;
        for (int i = 0; i < 2; ++i) {
            cin >> n >> e >> c;
            poly[i].resize(e + 1);
            while (true) {
                poly[i][e] = c;
                if (!--n) break;
                cin >> e >> c;
            }
        }
        quotient.resize(max(0, 1 + int(poly[0].size() - poly[1].size())));
        remainder = vector<double>(poly[0].begin(), poly[0].end());
    }

    void polyDivision()
    {
        for (int i = quotient.size() - 1; i > -1; --i) {
            quotient[i] = remainder.back() / poly[1].back();
            int diff = remainder.size() - poly[1].size();
            remainder.pop_back();
            for (int j = poly[1].size() - 2; j > -1; --j) remainder[j + diff] -= quotient[i] * poly[1][j];
        }
        formatPrint(quotient);
        formatPrint(remainder);
    }

private:
    void formatPrint(const vector<double> &x)
    {
        int notZero = 0;
        for (int i = x.size() - 1; i > -1; --i)
            if (abs(x[i]) >= 0.05) notZero += 1; // 'abs(const value_type&)': PTA(g++ 6.5) -ambiguous, g++ 8.1 -fine
        if (notZero == 0) {
            cout << "0 0 0.0\n";
        } else {
            cout << notZero;
            for (int i = x.size() - 1; i > -1; --i)
                if (abs(x[i]) >= 0.05) cout << ' ' << i << ' ' << fixed << setprecision(1) << x[i];
            cout << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.polyDivision();
    return 0;
}
