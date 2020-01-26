#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
private:
    static const int MAXN = 10000;
    bool isExist[MAXN] = {};
    int ufs[MAXN]; // union-find set
    double hnum[MAXN] = {};
    double harea[MAXN] = {};
    struct Family {
        int count = 0;
        double houses = 0.0, area = 0.0;
    };
    map<int, Family> record;

public:
    Solution()
    {
        for (int i = 0; i < MAXN; ++i) ufs[i] = i;
        int n;
        cin >> n;
        while (n--) { // input
            int p, f1, f2, k1, child;
            cin >> p >> f1 >> f2 >> k1;
            isExist[p] = true;
            if (f1 != -1) join(p, f1);
            if (f2 != -1) join(p, f2);
            for (int i = 0; i < k1; ++i) {
                cin >> child;
                join(p, child);
            }
            cin >> hnum[p] >> harea[p];
        }
        for (int i = 0; i < MAXN; ++i) { // combine person-info into families
            if (!isExist[i]) continue;
            int root = findRoot(i);
            record[root].count += 1;
            record[root].houses += hnum[i];
            record[root].area += harea[i];
        }
    }

    void printInfo()
    {
        vector<pair<int, Family>> tmp(record.begin(), record.end());
        sort(tmp.begin(), tmp.end(), [](const pair<int, Family> &x, const pair<int, Family> &y) {
            double avg1 = x.second.area / x.second.count, avg2 = y.second.area / y.second.count; // double, not int
            return avg1 > avg2 || avg1 == avg2 && x.first < y.first;
        });
        cout << tmp.size() << '\n' << setfill('0');
        for (const auto &p : tmp) {
            cout << setw(4) << p.first << ' ' << p.second.count << ' ';
            cout << fixed << setprecision(3) << p.second.houses / p.second.count << ' ';
            cout << fixed << setprecision(3) << p.second.area / p.second.count << '\n';
        }
    }

private:
    int findRoot(int x)
    {
        if (x == ufs[x]) return x;
        return ufs[x] = findRoot(ufs[x]); // pruning
    }

    void join(int x, int y)
    {
        x = findRoot(x), y = findRoot(y);
        if (x == y) return;
        isExist[y] = true;
        (x > y) ? ufs[x] = y : ufs[y] = x;
    }
};

int main(void)
{
    Solution s;
    s.printInfo();
    return 0;
}
