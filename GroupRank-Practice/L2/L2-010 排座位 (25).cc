#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> friends;          // union-find set
    vector<vector<bool>> hostile; // matrix
    int query;                    // num of queries

public:
    Solution()
    {
        int n, m, g1, g2, r;
        cin >> n >> m >> query;
        friends.resize(n + 1);
        for (int i = 0; i <= n; ++i) friends[i] = i;
        hostile = vector<vector<bool>>(n + 1, vector<bool>(n + 1));
        while (m--) {
            cin >> g1 >> g2 >> r;
            if (r == 1) {
                join(g1, g2);
            } else {
                hostile[g1][g2] = hostile[g2][g1] = true;
            }
        }
    }

    void relationQuery()
    {
        for (int i = 0, g1, g2; i < query; ++i) {
            cin >> g1 >> g2;
            int f1 = findRoot(g1), f2 = findRoot(g2);
            if (f1 == f2) {
                cout << (hostile[g1][g2] ? "OK but..." : "No problem") << '\n';
            } else {
                cout << (hostile[g1][g2] ? "No way" : "OK") << '\n';
            }
        }
    }

private:
    void join(int x, int y)
    {
        x = findRoot(x), y = findRoot(y);
        friends[y] = x;
    }

    int findRoot(int x)
    {
        if (x == friends[x]) return x;
        return friends[x] = findRoot(friends[x]);
    }
};

int main(void)
{
    Solution s;
    s.relationQuery();
    return 0;
}
