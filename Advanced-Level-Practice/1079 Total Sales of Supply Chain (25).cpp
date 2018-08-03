#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
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
    struct Node {
        int layer = 0;
        double amount = 0.0;
        vector<int> child;
    };
    int n;
    double p, r;
    Node *list;

  public:
    Solution()
    {
        cin >> n >> p >> r;
        r = 1 + r / 100;
        list = new Node[n];
        for (int i = 0, num; i < n; ++i) {
            cin >> num;
            if (num) {
                list[i].child.resize(num);
                for (int j = 0; j < num; ++j) cin >> list[i].child[j];
            } else {
                cin >> list[i].amount;
            }
        }
    }

    double getTotalSales()
    {
        double res = 0.0;
        queue<int> tmp;
        tmp.push(0);
        while (!tmp.empty()) {
            int node = tmp.front();
            tmp.pop();
            if (list[node].child.empty()) {
                res += list[node].amount * p * pow(r, list[node].layer);
            } else {
                for (const auto c : list[node].child) {
                    tmp.push(c);
                    list[c].layer = list[node].layer + 1;
                }
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    cout << fixed << setprecision(1) << s.getTotalSales();
    return 0;
}
