#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution    // always failed at Test point 2, 3 (18/25 scores, 4/6 test points).
{                 // Something wrong with the question that no code has been accepted yet.
  private:
    struct Person {
        string name;
        int age, netWorth;
        Person(string n, int a, int nw) : name(n), age(a), netWorth(nw) {}
    };
    struct SortRule {
        bool operator()(const Person &x, const Person &y)
        {
            return x.netWorth > y.netWorth ||
                   x.netWorth == y.netWorth && (x.age < y.age || x.age == y.age && x.name < y.name);
        }
    };
    int num, queries;
    int pnums[201]{};
    vector<Person> record;
    vector<Person *> reduced;

  public:
    Solution()
    {
        cin >> num >> queries;
        record.reserve(num);
        for (int i = 0; i < num; ++i) {
            string n;
            int a, nw;
            cin >> n >> a >> nw;
            record.emplace_back(n, a, nw);
        }
        sort(record.begin(), record.end(), SortRule());
        reduced.reserve(min(num, 20000));
        for (auto &r : record)
            if (pnums[r.age]++ < 100) reduced.push_back(&r);
    }

    void getRank() const
    {
        int n, left, right;
        for (int i = 1, count = 0; i <= queries; ++i, count = 0) {
            cin >> n >> left >> right;
            cout << (i > 1 ? "\n" : "") << "Case #" << i << ":";
            for (const auto &r : reduced) {
                if (r->age >= left && r->age <= right) {
                    cout << '\n' << r->name << ' ' << r->age << ' ' << r->netWorth;
                    if (++count == n) break;
                }
            }
            if (count == 0) cout << "\nNone";
        }
    }
};

int main(void)
{
    Solution s;
    s.getRank();
    return 0;
}
