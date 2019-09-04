#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    void getPalindrome()
    {
        string num;
        cin >> num;
        if (check(num)) {
            cout << num << " is a palindromic number.";
            return;
        }
        for (int i = 0; i < 10; ++i) {
            string rev = string(num.rbegin(), num.rend());
            cout << num << " + " << rev << " = ";
            plus(num, rev);
            cout << num << '\n';
            if (check(num)) {
                cout << num << " is a palindromic number.";
                return;
            }
        }
        cout << "Not found in 10 iterations.";
    }

private:
    bool check(const string &x)
    {
        int i = 0, j = x.size() - 1;
        while (i < j) {
            if (x[i] != x[j]) return false;
            ++i, --j;
        }
        return true;
    }

    void plus(string &x, const string &y)
    {
        int carry = 0;
        for (int i = x.size() - 1; i > -1; --i) {
            int t = x[i] + y[i] - 96 + carry;
            carry = t / 10;
            x[i] = t - 10 * carry + 48;
        }
        if (carry) x = char(carry + 48) + x;
    }
};

int main(void)
{
    Solution s;
    s.getPalindrome();
    return 0;
}
