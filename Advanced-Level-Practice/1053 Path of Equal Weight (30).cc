#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    struct Node {
        int weight;
        vector<int> children;
    };
    int n, m, target, root = 0;
    Node *list;

  public:
    Solution()
    {
        cin >> n >> m >> target;
        list = new Node[n];
        for (int i = 0; i < n; ++i) cin >> list[i].weight;
        for (int i = 0, id, num; i < m; ++i) {
            cin >> id >> num;
            list[id].children.resize(num);
            while (num--) cin >> list[id].children[num];
        }
    }

    void getPaths()
    {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, target, path, res);

        sort(res.begin(), res.end(), [](const vector<int> &x, const vector<int> &y) {
            int size = min(x.size(), y.size());
            for (int i = 0; i < size; ++i)
                if (x[i] != y[i]) return x[i] > y[i];
            return (x.size() > y.size() ? true : false);
        });

        for (const auto &x : res) {
            int size = x.size();
            cout << x[0];
            for (int i = 1; i < size; ++i) cout << ' ' << x[i];
            cout << '\n';
        }
    }

  private:
    void dfs(int node, int left, vector<int> &path, vector<vector<int>> &res)
    {
        if (list[node].weight == left && list[node].children.empty()) {
            res.push_back(path);
            res.back().push_back(list[node].weight);
            return;
        }
        if (list[node].weight > left || list[node].children.empty()) return;
        path.push_back(list[node].weight);
        for (const auto &c : list[node].children) dfs(c, left - list[node].weight, path, res);
        path.pop_back();
    }
};

int main(void)
{
    Solution s;
    s.getPaths();
    return 0;
}
