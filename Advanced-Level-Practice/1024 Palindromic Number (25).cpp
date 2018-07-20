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
    string num;
    int steps;

  public:
    Solution() { cin >> num >> steps; }

    void findPalindrome()
    {
        int i;
        for (i = 0; i < steps; ++i) {
            if (isPalindrome(num)) break;
            num = getPairedSum();
        }
        cout << num << '\n' << min(steps, i);
    }

  private:
    string getPairedSum()
    {
        string rev(num.rbegin(), num.rend()), ret = "";
        int carry = 0;
        for (int i = rev.size() - 1; i >= 0; --i) {
            int tmp = carry + num[i] + rev[i] - 96;
            carry = tmp / 10;
            ret += to_string(tmp % 10);
        }
        if (carry) ret += "1";
        return string(ret.rbegin(), ret.rend());
    }

    bool isPalindrome(const string &x)
    {
        int beg = 0, end = x.size() - 1;
        while (beg < end)
            if (x[beg++] != x[end--]) return false;
        return true;
    }
};

int main(void)
{
    Solution s;
    s.findPalindrome();
    return 0;
}
