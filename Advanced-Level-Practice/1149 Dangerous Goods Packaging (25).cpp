#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    unordered_map<int, unordered_set<int>> list;

public:
    void items()
    {
        int n, m;
        cin >> n >> m;
        while (n--) {
            int x, y;
            cin >> x >> y;
            list[x].insert(y);
            list[y].insert(x);
        }
        while (m--) {
            int x, y;
            cin >> x;
            unordered_set<int> tmp;
            while (x--) {
                cin >> y;
                tmp.insert(y);
            }
            bool flag = true;
            for (auto v : tmp) {
                if (helper(v, tmp)) {
                    flag = false;
                    break;
                }
            }
            if (flag) cout << "Yes\n";
        }
    }

private:
    bool helper(int x, const unordered_set<int> &t)
    {
        for (auto u : list[x])
            if (t.find(u) != t.end()) {
                cout << "No\n";
                return true;
            }
        return false;
    }
};

int main(void)
{
    Solution s;
    s.items();
    return 0;
}
