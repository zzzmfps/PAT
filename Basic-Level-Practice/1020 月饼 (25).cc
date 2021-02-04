#include <algorithm>
#include <iomanip>
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
    struct MoonCake {
        double quantity, price, totalPrice;
    };
    MoonCake *cakes;
    int types, demand;

  public:
    Solution()
    {
        cin >> types >> demand;
        cakes = new MoonCake[types];
        for (int i = 0; i < types; ++i) cin >> cakes[i].quantity;
        for (int i = 0; i < types; ++i) cin >> cakes[i].totalPrice;
        for (int i = 0; i < types; ++i) cakes[i].price = double(cakes[i].totalPrice) / cakes[i].quantity;
        sort(cakes, cakes + types, [](const auto &x, const auto &y) { return x.price > y.price; });
    }

    void getMaxProfit()
    {
        double profit = 0.0;
        for (int i = 0; i < types; ++i) {
            if (cakes[i].quantity >= demand) {
                profit += cakes[i].price * demand;
                break;
            } else {
                profit += cakes[i].totalPrice;
                demand -= cakes[i].quantity;
            }
        }
        cout << fixed << setprecision(2) << profit;
    }
};

int main(void)
{
    Solution s;
    s.getMaxProfit();
    return 0;
}
