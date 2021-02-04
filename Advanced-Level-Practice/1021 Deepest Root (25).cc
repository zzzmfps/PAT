#include <iostream>
#include <queue>
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
    int n;
    vector<int> *graph;

  public:
    Solution()
    {
        cin >> n;
        graph = new vector<int>[n + 1];
        for (int i = 1, n1, n2; i < n; ++i) {
            cin >> n1 >> n2;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
    }

    void printDeepestRoot()
    {
        if (n == 1) {
            cout << 1;
            return;
        }
        int comp = getComponentNumber();
        if (comp > 1) {
            cout << "Error: " << comp << " components";
            return;
        }

        vector<int> res;
        for (int i = 1, maxHeight = 0; i <= n; ++i)
            if (graph[i].size() == 1) {
                int x = getHeight(i);
                if (x >= maxHeight) {
                    if (x > maxHeight) res.clear();
                    maxHeight = x;
                    res.push_back(i);
                }
            }
        for (const auto x : res) cout << x << '\n';
        delete[] graph;
    }

  private:
    int getComponentNumber()
    {
        int count = 0;
        bool *isVisited = new bool[n + 1]{};
        queue<int> tmp;

        for (int i = 1; i <= n; ++i) {
            if (!isVisited[i]) {
                tmp.push(i);
                ++count, isVisited[i] = true;
                while (!tmp.empty()) helper(tmp, isVisited);
            }
        }
        delete[] isVisited;
        return count;
    }

    int getHeight(int node)
    {
        int mh = 0;
        bool *isVisited = new bool[n + 1]{};
        queue<int> tmp;
        tmp.push(node);
        isVisited[node] = true;

        while (!tmp.empty()) {
            ++mh;
            helper(tmp, isVisited);
        }
        delete[] isVisited;
        return mh;
    }

    void helper(queue<int> &tmp, bool *isVisited)
    {
        for (int i = tmp.size(); i > 0; --i) {
            int x = tmp.front();
            tmp.pop();
            for (const auto y : graph[x])
                if (!isVisited[y]) {
                    isVisited[y] = true;
                    tmp.push(y);
                }
        }
    }
};

int main(void)
{
    Solution s;
    s.printDeepestRoot();
    return 0;
}
