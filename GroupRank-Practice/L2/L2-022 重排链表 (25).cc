#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
private:
    int root, n;
    pair<int, int> link[100000]; // val, next

public:
    Solution()
    {
        cin >> root >> n;
        while (n--) {
            int cur, val, _next;
            cin >> cur >> val >> _next;
            link[cur] = make_pair(val, _next);
        }
        int idx = root; // some nodes are not linked, `n` should be re-calculate
        while (idx != -1) ++n, idx = link[idx].second;
        ++n; // n == -1 when ended the while-loop
    }

    void rearrange()
    {
        vector<pair<int, int>> res(n); // cur, val
        int i, j = root;
        for (i = 1; i < n; i += 2) {
            res[i] = make_pair(j, link[j].first);
            j = link[j].second;
        }
        for (i -= (n & 1 ? 1 : 3); i > -1; i -= 2) {
            res[i] = make_pair(j, link[j].first);
            j = link[j].second;
        }
        cout << setfill('0');
        cout << setw(5) << res[0].first << ' ' << res[0].second;
        for (int k = 1; k < n; ++k) {
            int &x = res[k].first, &y = res[k].second;
            cout << ' ' << setw(5) << x << '\n' << setw(5) << x << ' ' << y;
        }
        cout << " -1";
    }
};

int main(void)
{
    Solution s;
    s.rearrange();
    return 0;
}
