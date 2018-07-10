#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    int nc, np;
    vector<int> coupons, products;

  public:
    Solution()
    {
        cin >> nc;
        coupons.resize(nc);
        for (int i = 0; i < nc; ++i) cin >> coupons[i];
        sort(coupons.begin(), coupons.end());
        cin >> np;
        products.resize(np);
        for (int i = 0; i < np; ++i) cin >> products[i];
        sort(products.begin(), products.end());
    }

    int getMaxMoneyBack()
    {
        int lc = 0, rc = nc - 1, lp = 0, rp = np - 1;
        int amount = 0;
        while (lc <= rc && lp <= rp) {
            if (coupons[lc] >= 0 || products[lp] >= 0) break;
            amount += coupons[lc++] * products[lp++];
        }
        while (lc <= rc && lp <= rp) {
            if (coupons[rc] <= 0 || products[rp] <= 0) break;
            amount += coupons[rc--] * products[rp--];
        }
        return amount;
    }
};

int main(void)
{
    Solution s;
    cout << s.getMaxMoneyBack();
    return 0;
}
