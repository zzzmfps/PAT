#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    int n, m, q;
    bool **graph;

  public:
    Solution()
    {
        cin >> n >> m;
        graph = new bool *[n + 1];
        for (int i = 1; i <= n; ++i) graph[i] = new bool[n + 1];
        for (int i = 0, j, k; i < m; ++i) {
            cin >> j >> k;
            graph[j][k] = graph[k][j] = true;
        }
    }

    ~Solution()
    {
        for (int i = 1; i <= n; ++i) delete[] graph[i];
        delete[] graph;
    }

    void printResult()
    {
        cin >> q;
        for (int i = 0, k; i < q; ++i) {
            cin >> k;
            if (k != n + 1) {
                cout << "NO\n";
                cin.ignore(0x7FFFFFFF, '\n');
                continue;
            }
            bool *isVisited = new bool[n + 1]{};
            int beg;
            cin >> beg;
            isVisited[beg] = true;
            for (int j = 1, num1 = beg, num2; j < k; ++j) {
                cin >> num2;
                if (graph[num1][num2] && !isVisited[num2]) {
                    isVisited[num2] = true;
                    num1 = num2;
                } else if (graph[num1][num2] && j == n && num2 == beg) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                    cin.ignore(0x7FFFFFFF, '\n');
                    break;
                }
            }
            delete[] isVisited;
        }
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
