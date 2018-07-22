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
    int n, expa, expb;
    string a, b, va, vb;

  public:
    Solution()
    {
        cin >> n >> a >> b;
        expa = getExpAndValid(a, va), expb = getExpAndValid(b, vb);
    }

    void printResult()
    {
        bool isEqual = (va == vb);
        cout << (isEqual ? "YES" : "NO");
        formatOutput(va, expa);
        if (!isEqual) formatOutput(vb, expb);
    }

  private:
    void formatOutput(const string &x, int exp) { cout << " 0." << x << string(n - x.size(), '0') << "*10^" << exp; }

    int getExpAndValid(const string &x, string &y)
    {
        int valid = x.find_first_not_of("0."), dot = x.find('.');
        y = "0";
        if (valid == string::npos) return 0;
        y = x.substr(valid, n);
        if (dot == string::npos) return x.size() - valid;
        int dot2 = y.find('.');
        if (dot2 != string::npos) {
            y.erase(dot2, 1);
            if (valid + n < x.size()) y += x[valid + n];
        }
        return dot - valid + (dot < valid ? 1 : 0);
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
