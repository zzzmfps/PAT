#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
private:
    const int LIMIT = 0x3FFFFFFF;
    int n, m;
    int **path;

public:
    Solution()
    {
        cin >> n >> m;
        path = new int *[n + 1];
        for (int i = 1; i <= n; ++i) {
            path[i] = new int[n + 1];
            fill_n(path[i] + 1, n, LIMIT);
        }
        for (int i = 0; i < m; ++i) {
            int a, b, v;
            cin >> a >> b >> v;
            path[a][b] = path[b][a] = v;
        }
    }

    ~Solution()
    {
        for (int i = 1; i <= n; ++i) delete[] path[i];
        delete[] path;
    }

    void travellingSalesmanProblem()
    {
        int k, minDist = LIMIT, idx = 0;
        cin >> k;
        for (int i = 1; i <= k; ++i) {
            int city, last, dist = 0;
            bool *isVisited = new bool[n + 1] {};
            cin >> city >> last;
            int start = last;
            bool flag = false;
            for (int j = 1, cur; j < city; ++j) {
                cin >> cur;
                if (path[last][cur] == LIMIT) { // cannot from cityLast to cityCur
                    flag = true;
                    cin.ignore(LIMIT, '\n');  // ignore this line
                    break;
                }
                isVisited[cur] = true;  // don't need set isVisited[start]
                dist += path[last][cur];
                last = cur;
            }
            cout << "Path " << i << ": ";
            if (flag) {
                cout << "NA (Not a TS cycle)\n";
            } else {
                cout << dist << ' ';
                if (last != start || any_of(isVisited + 1, isVisited + n + 1, [](bool x) { return !x; })) {
                    cout << "(Not a TS cycle)\n";
                } else {
                    cout << (city == n + 1 ? "(TS simple cycle)" : "(TS cycle)") << '\n';
                    if (dist < minDist) minDist = dist, idx = i;
                }
            }
            delete[] isVisited;
        }
        cout << "Shortest Dist(" << idx << ") = " << minDist;
    }
};

int main(void)
{
    Solution s;
    s.travellingSalesmanProblem();
    return 0;
}
