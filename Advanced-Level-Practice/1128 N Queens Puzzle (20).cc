#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void checkSolution()
    {
        int k;
        cin >> k;
        while (k--) {
            int n, i, v;
            cin >> n;
            vector<bool> row(n + 1), left(2 * n + 1), right(2 * n);
            for (i = 1; i <= n; ++i) {
                cin >> v;
                if (row[v] || left[v + i] || right[n + v - i]) {
                    cout << "NO\n";
                    cin.ignore(0x7FFFFFFF, '\n');
                    break;
                }
                row[v] = left[v + i] = right[n + v - i] = true;
            }
            if (i > n) cout << "YES\n";
        }
    }
};

int main(void)
{
    Solution s;
    s.checkSolution();
    return 0;
}
