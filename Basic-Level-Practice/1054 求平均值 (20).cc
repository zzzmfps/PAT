#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    int n;
    double sum = 0.0;

  public:
    Solution() { cin >> n; }

    void findAverage()
    {
        string tmp;
        for (int i = 0, j = n; i < j; ++i) {
            cin >> tmp;
            if (!checkAndAccumulate(tmp)) {
                --n;
                cout << "ERROR: " << tmp << " is not a legal number\n";
            }
        }
        cout << "The average of " << n << " number" << (n == 1 ? "" : "s") << " is ";
        if (n) {
            cout << fixed << setprecision(2) << sum / n;
        } else {
            cout << "Undefined";
        }
    }

  private:
    bool checkAndAccumulate(const string &x)
    {
        if (x[0] != '-' && x[0] != '+' && (x[0] < '0' || x[0] > '9')) return false;
        int len = x.size();
        for (int i = 1, dot = 0; i < len; ++i) {
            if (x[i] == '.') {
                if (len - i > 3 || ++dot == 2) return false;
                continue;
            }
            if (x[i] < '0' || x[i] > '9') return false;
        }
        double y = stod(x);
        if (y < -1000 || y > 1000) return false;
        sum += y;
        return true;
    }
};

int main(void)
{
    Solution s;
    s.findAverage();
    return 0;
}
