#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
private:
    unordered_set<string> us;

public:
    Solution()
    {
        int n;
        cin >> n;
        while (n--) {
            string name;
            cin >> name;
            us.insert(name);
        }
    }

    void check()
    {
        vector<pair<string, int>> res;
        int m, _sum = 0;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            string name;
            int count;
            cin >> name >> count;
            _sum += count;
            if (us.find(name) == us.end()) res.emplace_back(name, count);
        }
        double avg = _sum / double(m);
        sort(res.begin(), res.end(),
             [](const pair<string, int> &x, const pair<string, int> &y) { return x.first < y.first; });
        bool flag = false;
        for (auto &p : res)
            if (p.second > avg) cout << p.first << '\n', flag = true;
        if (!flag) cout << "Bing Mei You";
    }
};

int main(void)
{
    Solution s;
    s.check();
    return 0;
}
