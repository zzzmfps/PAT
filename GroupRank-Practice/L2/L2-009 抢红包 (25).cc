#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    struct Person {
        int index;
        int cents = 0, num = 0;
    };
    vector<Person> record;

public:
    Solution()
    {
        int n;
        cin >> n;
        record.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            record[i].index = i;
            int k, j, money;
            cin >> k;
            while (k--) {
                cin >> j >> money;
                record[i].cents -= money;
                record[j].cents += money, record[j].num += 1;
            }
        }
    }

    void summary()
    {
        record.erase(record.begin());
        sort(record.begin(), record.end(), [](const Person &x, const Person &y) {
            return x.cents > y.cents || x.cents == y.cents && x.num > y.num ||
                   x.cents == y.cents && x.num == y.num && x.index < y.index;
        });
        for (const auto &p : record) cout << p.index << ' ' << fixed << setprecision(2) << p.cents / 100.0 << '\n';
    }
};

int main(void)
{
    Solution s;
    s.summary();
    return 0;
}
