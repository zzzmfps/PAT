#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int city, road;
    vector<vector<int>> graph;

public:
    Solution()
    {
        cin >> city >> road;
        graph.resize(city + 1);
        for (int i = 0, c1, c2; i < road; ++i) {
            cin >> c1 >> c2;
            graph[c1].push_back(c2);
        }
    }

    void battle()
    {
        int k, c, c1;
        cin >> k;
        while (k--) {
            vector<bool> conquered(city + 1);
            cin >> c;
            while (c--) {
                cin >> c1;
                conquered[c1] = true;
            }
            bool flag = true;
            for (int i = 1; flag && i <= city; ++i) {
                if (conquered[i]) continue;
                auto &v = graph[i];
                flag = all_of(v.begin(), v.end(), [&](int c) { return conquered[c]; });
            }
            cout << (flag ? "YES" : "NO") << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.battle();
    return 0;
}
