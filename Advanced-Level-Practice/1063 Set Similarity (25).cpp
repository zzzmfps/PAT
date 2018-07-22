#include <iomanip>
#include <iostream>
#include <set>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    set<int> *sets;

  public:
    Solution()
    {
        int n, m, elem;
        cin >> n;
        sets = new set<int>[n + 1];
        for (int i = 1; i <= n; ++i) {
            cin >> m;
            while (m--) {
                cin >> elem;
                sets[i].insert(elem);
            }
        }
    }

    void getSimilarity()
    {
        cout << fixed << setprecision(1);
        int query, i, j;
        cin >> query;
        while (query--) {
            cin >> i >> j;
            int commons = getCommonElementNumber(i, j);
            cout << 100.0 * commons / (sets[i].size() + sets[j].size() - commons) << "%\n";
        }
    }

  private:
    int getCommonElementNumber(int i, int j)
    {
        auto x1 = sets[i].begin(), y1 = sets[j].begin();
        auto x2 = sets[i].end(), y2 = sets[j].end();
        int res = 0;
        while (x1 != x2 && y1 != y2) {
            if (*x1 == *y1) {
                ++res, ++x1, ++y1;
            } else if (*x1 < *y1) {
                ++x1;
            } else {
                ++y1;
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    s.getSimilarity();
    return 0;
}
