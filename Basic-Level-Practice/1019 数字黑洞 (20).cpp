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
    string num;

  public:
    Solution()
    {
        cin >> num;
        num = formatter(num);
    }

    void blackHole()
    {
        string left = "    ", right = "    ";
        while (true) {
            getMinMax(left, right);
            cout << right << " - " << left << " = ";
            strMinus(left, right);
            cout << num << '\n';
            if (num == "0000" || num == "6174") break;
        }
    }

  private:
    void getMinMax(string &x, string &y)
    {
        partial_sort_copy(num.begin(), num.end(), x.begin(), x.end());
        copy(x.rbegin(), x.rend(), y.begin());
    }

    void strMinus(const string &x, const string &y)
    {
        string ret = to_string(stoi(y) - stoi(x));
        num = formatter(ret);
    }

    string formatter(const string &x) { return string(4 - x.size(), '0') + x; }
};

int main(void)
{
    Solution s;
    s.blackHole();
    return 0;
}
