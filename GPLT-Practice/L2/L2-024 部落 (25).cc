#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
private:
    int ufs[10001];
    unordered_set<int> rec;

public:
    Solution()
    {
        for (int i = 0; i < 10001; ++i) ufs[i] = i;
        int n, k, p1, p2;
        cin >> n;
        while (n--) {
            cin >> k >> p1;
            rec.insert(p1);
            while (--k) {
                cin >> p2;
                rec.insert(p2);
                join(p1, p2);
            }
        }
    }

    void check()
    {
        unordered_set<int> tmp;
        for (auto p : rec) tmp.insert(findRoot(p));
        cout << rec.size() << ' ' << tmp.size() << '\n';
        int n, p1, p2;
        cin >> n;
        while (n--) {
            cin >> p1 >> p2;
            cout << (findRoot(p1) == findRoot(p2) ? 'Y' : 'N') << '\n';
        }
    }

private:
    int findRoot(int x)
    {
        if (ufs[x] == x) return x;
        return ufs[x] = findRoot(ufs[x]);
    }

    void join(int x, int y)
    {
        x = findRoot(x), y = findRoot(y);
        ufs[y] = x;
    }
};

int main(void)
{
    Solution s;
    s.check();
    return 0;
}
