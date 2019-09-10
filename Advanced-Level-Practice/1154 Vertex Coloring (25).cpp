#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    void vertexColoring()
    {
        int nv, ne;
        cin >> nv >> ne;
        vector<unordered_set<int>> graph(nv);
        while (ne--) {
            int a, b;
            cin >> a >> b;
            graph[a].insert(b);  // regard it as a directed graph
        }
        int k;
        cin >> k;
        while (k--) {
            vector<int> colors(nv);
            for (int i = 0, c; i < nv; ++i) cin >> colors[i];
            bool flag = true;
            for (int i = 0, c; flag && i < nv; ++i) {
                for (auto x : graph[i]) {
                    if (colors[x] == colors[i]) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                unordered_set<int> nums(colors.begin(), colors.end());
                cout << nums.size() << "-coloring\n";
            } else {
                cout << "No\n";
            }
        }
    }
};

int main(void)
{
    Solution s;
    s.vertexColoring();
    return 0;
}
