#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution
{
private:
    unordered_map<string, unordered_set<string>> relations;

public:
    Solution()
    {
        int np, nr;
        cin >> np >> nr;
        while (nr--) {
            string x, y;
            cin >> x >> y;
            relations[x].insert(y);
            relations[y].insert(x);
        }
    }

    void firstContact()
    {
        int k;
        cin >> k;
        while (k--) {
            string a, b;
            cin >> a >> b;
            set<pair<string, string>> res;
            // a -> c -> d -> b
            for (auto &c : relations[a]) {  // c the friends of a
                if (a.size() != c.size() || b == c) continue;   // a and c are of the same gender
                for (auto &d : relations[b]) {  // d the friends of b
                    if (b.size() != d.size() || a == d) continue;    // b and d are of the same gender
                    auto &tmp = relations[c];
                    if (tmp.find(d) == tmp.end()) continue; // d the friends of c
                    res.emplace((c[0] == '-' ? c.substr(1) : c), (d[0] == '-' ? d.substr(1) : d));
                }
            }
            cout << res.size() << '\n';
            for (auto &p : res) cout << p.first << ' ' << p.second << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.firstContact();
    return 0;
}
