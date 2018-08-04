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
    int n, root;
    double p, r;
    vector<int> *list;

  public:
    Solution()
    {
        cin >> n >> p >> r;
        r = 1 + r / 100;
        list = new vector<int>[n];
        for (int i = 0, num; i < n; ++i) {
            cin >> num;
            if (num != -1) {
                list[num].push_back(i);
            } else {
                root = i;
            }
        }
    }

    void getHighestPrice()
    {
        int count, layer = 0;
        queue<int> tmp;
        tmp.push(root);
        while (!tmp.empty()) {
            ++layer, count = tmp.size();
            for (int i = count; i > 0; --i) {
                int x = tmp.front();
                tmp.pop();
                for (const auto y : list[x]) tmp.push(y);
            }
        }
        double price = p * pow(r, layer - 1);
        cout << fixed << setprecision(2) << price << ' ' << count;
    }
};

int main(void)
{
    Solution s;
    s.getHighestPrice();
    return 0;
}
