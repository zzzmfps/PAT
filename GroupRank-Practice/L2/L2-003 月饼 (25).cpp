#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
private:
    int types, demands;
    vector<double> stocks;
    vector<double> values;

public:
    Solution()
    {
        cin >> types >> demands;
        stocks.resize(types);
        for (int i = 0; i < types; ++i) cin >> stocks[i];
        values.resize(types);
        for (int i = 0; i < types; ++i) cin >> values[i];
    }

    void maxProfit()
    {
        multimap<double, int> rank; // different mooncakes may have the same price
        for (int i = 0; i < types; ++i) rank.emplace(-values[i] / double(stocks[i]), i);
        double res = 0.0, left = demands;
        for (auto &p : rank) {
            double price = p.first, type = p.second;
            if (stocks[type] < left) {
                res += values[type];
                left -= stocks[type];
            } else {
                res -= left * price; // price is negative
                break;
            }
        }
        cout << fixed << setprecision(2) << res;
    }
};

int main(void)
{
    Solution s;
    s.maxProfit();
    return 0;
}
