#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    unordered_map<char, long long> convert;
    string n1, n2;
    long long radix, num1;

  public:
    Solution()
    {
        for (int i = 0; i < 10; ++i) convert[48 + i] = i;
        for (int i = 10; i < 36; ++i) convert[87 + i] = i;
        int tag;
        cin >> n1 >> n2 >> tag >> radix;
        if (tag == 2) swap(n1, n2);   // always makes n1 known
        num1 = toDecimal(n1, radix);  // decimal of n1
    }

    void getAnotherRadix()  // get radix of n2
    {
        long long lradix = 2, rradix = 0x7FFFFFFF;
        modifyBorderLimit(lradix, rradix);
        while (lradix <= rradix) {
            long long mid = lradix + (rradix - lradix) / 2;
            long long tmp = toDecimal(n2, mid);  // decimal of n2
            if (tmp == num1) {
                cout << (n2.size() == 1 ? lradix : mid);
                return;
            } else if (tmp > num1 || tmp < 0) {  // or overflow
                rradix = mid - 1;
            } else {
                lradix = mid + 1;
            }
        }
        cout << "Impossible";
    }

  private:
    long long toDecimal(const string &x, long long r)
    {
        long long ret = 0;
        for (int i = 0, size = x.size(); i < size; ++i) ret = ret * r + convert[x[i]];
        return ret;
    }

    void modifyBorderLimit(long long &l, long long &r)
    {
        int size1 = n1.size(), size2 = n2.size();
        if (size1 < size2 || size1 == size2 && n1 < n2) {
            r = radix - 1;
        } else if (size1 > size2 || size1 == size2 && n1 > n2) {
            l = radix + 1;
        }
        for (const auto c : n2) l = max(l, 1 + convert[c]);
        r = min(r, max(l, num1));
    }
};

int main(void)
{
    Solution s;
    s.getAnotherRadix();
    return 0;
}
