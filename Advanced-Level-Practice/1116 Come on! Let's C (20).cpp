#include <iomanip>
#include <iostream>
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
    int n;
    unordered_map<int, int> ranks;
    bool *isComposite;

  public:
    Solution()
    {
        cin >> n;

        for (int i = 1, j; i <= n; ++i) {
            cin >> j;
            ranks[j] = i;
        }

        isComposite = new bool[10001]{};
        for (int i = 2; i < 101; ++i) {  // 101 == ceil(sqrt(10001))
            if (isComposite[i]) continue;
            for (int j = i * i; j < 10001; j += i) isComposite[j] = true;
        }
    }

    ~Solution() { delete[] isComposite; }

    void getPrizes()
    {
        int m;
        cin >> m;
        for (int i = 0, j; i < m; ++i) {
            cin >> j;
            cout << setfill('0') << setw(4) << j << ": ";
            if (ranks.find(j) == ranks.end()) {
                cout << "Are you kidding?\n";
                continue;
            }
            int &order = ranks[j];
            if (order == 0) {
                cout << "Checked\n";
            } else {
                cout << (order == 1 ? "Mystery Award" : isComposite[order] ? "Chocolate" : "Minion") << '\n';
                order = 0;
            }
        }
    }
};

int main(void)
{
    Solution s;
    s.getPrizes();
    return 0;
}
