#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    int np, ng;
    queue<int> x;
    pair<int, int> *table;
    unordered_map<int, int> convert;

  public:
    Solution()
    {
        cin >> np >> ng;
        table = new pair<int, int>[np];
        for (int i = 0, tmp; i < np; ++i) {
            cin >> tmp;
            table[i].first = tmp;
            convert[tmp] = i;
        }
        for (int i = 0, tmp; i < np; ++i) {
            cin >> tmp;
            x.push(table[tmp].first);
        }
    }

    void getRanks()
    {
        if (np == 1 && ng == 1) {
            cout<<'1';
            return;
        }
        int rounds = ceil(log(np) / log(ng)), groups = np;
        while (rounds--) {
            groups = ceil(groups / double(ng));
            queue<int> tmp;
            for (int i = 0; i < groups; ++i) {
                int max = x.front();
                x.pop();
                for (int j = 1; j < ng && !x.empty(); ++j) {
                    if (max < x.front()) swap(max, x.front());
                    table[convert[x.front()]].second = groups + 1;
                    x.pop();
                }
                tmp.push(max);
            }
            x.swap(tmp);
        }
        table[convert[x.front()]].second = 1;
        cout << table[0].second;
        for (int i = 1; i < np; ++i) cout << ' ' << table[i].second;
    }
};

int main(void)
{
    Solution s;
    s.getRanks();
    return 0;
}
