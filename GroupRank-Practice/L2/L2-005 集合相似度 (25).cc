#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<set<int>> record;

public:
    Solution()
    {
        int n;
        cin >> n;
        record.resize(n + 1);
        for (int i = 1, k, v; i <= n; ++i) {
            cin >> k;
            for (int j = 0; j < k; ++j) {
                cin >> v;
                record[i].insert(v);
            }
        }
    }

    void getSimilarity()
    {
        int n, i, j;
        cin >> n;
        while (n--) {
            cin >> i >> j;
            cout << fixed << setprecision(2) << 100.0 * helper(i, j) << "%\n";
        }
    }

private:
    double helper(int i, int j)
    {
        auto it1 = record[i].begin(), it2 = record[i].end();
        auto it3 = record[j].begin(), it4 = record[j].end();
        double nc = 0.0, nt = 0.0;
        while (it1 != it2 && it3 != it4) {
            if (*it1 == *it3) {
                nc += 1, ++it1, ++it3;
            } else {
                *it1 < *it3 ? ++it1 : ++it3;
            }
            nt += 1;
        }
        nt += distance(it1, it2) + distance(it3, it4);
        return nc / nt;
    }
};

int main(void)
{
    Solution s;
    s.getSimilarity();
    return 0;
}
