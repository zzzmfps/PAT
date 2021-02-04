#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
private:
    int v, e, k;
    vector<vector<bool>> graph;

public:
    Solution()
    {
        cin >> v >> e >> k;
        graph = vector<vector<bool>>(v + 1, vector<bool>(v + 1));
        for (int i = 0, v1, v2; i < e; ++i) {
            cin >> v1 >> v2;
            graph[v1][v2] = graph[v2][v1] = true;
        }
    }

    void colorTheGraph()
    {
        int n;
        cin >> n;
        while (n--) check();
    }

private:
    void check()
    {
        vector<int> colors(v + 1);
        unordered_set<int> us;
        for (int i = 1; i <= v; ++i) cin >> colors[i], us.insert(colors[i]);
        if (us.size() != k) {
            cout << "No\n";
            return;
        }
        for (int i = 1; i <= v; ++i) {
            for (int j = 1; j <= v; ++j) {
                if (i == j || !graph[i][j]) continue;
                if (colors[i] == colors[j]) {
                    cout << "No\n";
                    return;
                }
            }
        }
        cout << "Yes\n";
    }
};

int main(void)
{
    Solution s;
    s.colorTheGraph();
    return 0;
}
