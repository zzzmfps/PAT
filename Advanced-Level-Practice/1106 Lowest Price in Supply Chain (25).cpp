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
    int n, root = 0;
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
            if (!num) continue;
            list[i].resize(num);
            for (int j = 0; j < num; ++j) cin >> list[i][j];
        }
    }

    void getLowestPrice()
    {
        int count = 0, layer = 0;
        queue<int> tmp;
        tmp.push(root);
        while (!tmp.empty()) {
            ++layer;
            for (int i = tmp.size(); i > 0; --i) {
                int x = tmp.front();
                if (list[x].empty()) ++count;
                tmp.pop();
                for (const auto y : list[x]) tmp.push(y);
            }
            if (count) break;
        }
        double price = p * pow(r, layer - 1);
        cout << fixed << setprecision(4) << price << ' ' << count;
    }
};

int main(void)
{
    Solution s;
    s.getLowestPrice();
    return 0;
}
