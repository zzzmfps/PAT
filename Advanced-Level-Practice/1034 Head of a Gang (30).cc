#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_set>
using namespace std;

static int a = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    struct Vertex {
        int weight = 0;
        bool isVisited = false;
        unordered_set<int> edges;
    };
    int n, threshold;
    Vertex graph[17576];

  public:
    Solution()
    {
        cin >> n >> threshold;
        string beg, end;
        int tmpw;
        for (int i = 0; i < n; ++i) {
            cin >> beg >> end >> tmpw;
            int hbeg = hash(beg), hend = hash(end);
            graph[hbeg].weight += tmpw;
            graph[hend].weight += tmpw;
            graph[hbeg].edges.insert(hend);
            graph[hend].edges.insert(hbeg);
        }
    }

    void printGangs()
    {
        map<string, int> res;
        for (int i = 0; i < 17576; ++i) {
            if (graph[i].edges.empty() || graph[i].isVisited) continue;
            graph[i].isVisited = true;
            processCluster(i, res);
        }
        cout << res.size();
        for (const auto &r : res) cout << '\n' << r.first << ' ' << r.second;
    }

  private:
    void processCluster(int x, map<string, int> &res)
    {
        stack<int> tmp;
        tmp.push(x);
        int count = 1, maxWeight = 0, head = -1;
        double totalWeight = 0.0;
        while (!tmp.empty()) {
            int y = tmp.top();
            tmp.pop();
            totalWeight += graph[y].weight / 2.0;
            if (graph[y].weight > maxWeight) {
                head = y;
                maxWeight = graph[y].weight;
            }
            for (auto z : graph[y].edges)
                if (!graph[z].isVisited) {
                    graph[z].isVisited = true;
                    tmp.push(z);
                    ++count;
                }
        }
        if (count > 2 && totalWeight > threshold) res[reverseHash(head)] = count;
    }

    int hash(const string &x) { return x[0] * 676 + x[1] * 26 + x[2] - 45695; }

    string reverseHash(int x) { return string(1, 'A' + x / 676) + char('A' + x % 676 / 26) + char('A' + x % 26); }
};

int main(void)
{
    Solution s;
    s.printGangs();
    return 0;
}
