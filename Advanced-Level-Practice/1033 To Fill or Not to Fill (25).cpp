#include <iomanip>
#include <iostream>
#include <map>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    map<double, double> sta;
    double cmax, dist, davg, num;
    double onceMax, curDist = 0.0, curGas = 0.0, curPrice, totalCost = 0.0;

  public:
    Solution()
    {
        cin >> cmax >> dist >> davg >> num;
        double p;
        int d;
        for (int i = 0; i < num; ++i) {
            cin >> p >> d;
            sta[d] = p;
        }
        sta[dist] = 0.0;
        onceMax = cmax * davg;
        curPrice = sta[0];
    }

    void getMinCostOrMaxDist()
    {
        if (curPrice == 0.0) {
            cout << "The maximum travel distance = 0.00";
            return;
        }
        cout << fixed << setprecision(2);
        auto trav = sta.begin();
        while (curDist < dist) {
            auto p1 = next(trav);
            auto p2 = sta.upper_bound(curDist + onceMax);
            if (p1 == p2) {
                cout << "The maximum travel distance = " << curDist + onceMax;
                return;
            }
            trav = getMinPrice(p1, p2);
            if (trav->second <= curPrice) {
                if (trav->first - curDist > curGas * davg) {
                    totalCost += curPrice * ((trav->first - curDist) / davg - curGas);
                    curGas = 0;
                } else {
                    curGas -= (trav->first - curDist) / davg;
                }
            } else {
                totalCost += curPrice * (cmax - curGas);
                curGas = cmax - (trav->first - curDist) / davg;
            }
            curDist = trav->first, curPrice = trav->second;
        }
        cout << totalCost;
    }

  private:
    typedef map<double, double>::iterator map_dd_iter;
    map_dd_iter getMinPrice(map_dd_iter &x, map_dd_iter &y)
    {
        auto tmp = x;
        for (auto p = x; p != y; ++p) {
            if (p->second < curPrice) return p;
            if (p->second < tmp->second) tmp = p;
        }
        return tmp;
    }
};

int main(void)
{
    Solution s;
    s.getMinCostOrMaxDist();
    return 0;
}
