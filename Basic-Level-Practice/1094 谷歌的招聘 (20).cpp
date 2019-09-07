#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    void findPrime()
    {
        int l, k;
        string str;
        cin >> l >> k >> str;
        if (l >= k) {
            int num = stoi(str.substr(0, k)), tmp = pow(10, k - 1);
            cout << setfill('0');
            if (check(num)) {
                cout << setw(k) << num;
                return;
            }
            for (int i = k; i < l; ++i) {
                num = num % tmp * 10 + str[i] - 48;
                if (check(num)) {
                    cout << setw(k) << num;
                    return;
                }
            }
        }
        cout << 404;
    }

private:
    bool check(int n)
    {
        if (n < 4) return true;
        for (int i = 2, s = sqrt(n) + 1; i < s; ++i)
            if (n % i == 0) return false;
        return true;
    }
};

int main(void)
{
    Solution s;
    s.findPrime();
    return 0;
}
