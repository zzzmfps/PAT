#include <iostream>
#include <vector>
using namespace std;

struct Vertex
{
    int indegree = 0;
    vector<int> out;
};

class Solution
{
public:
    void topologicalOrder()
    {
        int n, m;
        cin >> n >> m;
        vector<Vertex> tmp(n + 1);
        while (m--) {
            int a, b;
            cin >> a >> b;
            tmp[a].out.push_back(b);
            tmp[b].indegree += 1;
        }

        int k;
        cin >> k;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            int *in = new int[n + 1];
            for (int j = 1; j <= n; ++j) in[j] = tmp[j].indegree;
            for (int j = 0, v; j < n; ++j) {
                cin >> v;
                if (in[v] > 0) {
                    res.push_back(i);
                    cin.ignore(0x7FFFFFFF, '\n');
                    break;
                }
                for (auto o : tmp[v].out) in[o] -= 1;
            }
            delete[] in;
        }

        cout << res[0];
        for (int i = 1, size = res.size(); i < size; ++i) cout << ' ' << res[i];
    }
};

int main(void)
{
    Solution s;
    s.topologicalOrder();
    return 0;
}
