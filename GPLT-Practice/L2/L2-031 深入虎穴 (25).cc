#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
private:
    int n, start;
    vector<vector<int>> maze;

public:
    Solution()
    {
        cin >> n;
        maze.resize(n + 1);
        bool *isNotStart = new bool[n + 1]{};
        for (int i = 1, j; i <= n; ++i) {
            cin >> j;
            maze[i].resize(j);
            while (j--) {
                cin >> maze[i][j];
                isNotStart[maze[i][j]] = true;
            }
        }
        for (int i = 1; i <= n; ++i) { // find the entrance
            if (isNotStart[i]) continue;
            start = i;
            break;
        }
        delete[] isNotStart;
    }

    int deepset()
    {
        queue<int> q;
        q.push(start);
        while (true) {
            if (q.size() == 1 && maze[q.front()].empty()) return q.front(); // deepest door
            for (int i = q.size(); i > 0; --i) {
                int curDoor = q.front();
                q.pop();
                for (auto nextDoor : maze[curDoor]) q.push(nextDoor); // since this maze is like a tree
            }
        }
        return -1; // fails somehow
    }
};

int main(void)
{
    Solution s;
    cout << s.deepset();
    return 0;
}
