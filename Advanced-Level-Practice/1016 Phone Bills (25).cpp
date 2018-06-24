#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    struct Record {
        string name;
        int month, day, hour, minute;
        string status;
        Record(string n, int m, int d, int h, int ms, string s)
            : name(n), month(m), day(d), hour(h), minute(ms), status(s)
        {
        }
    };

    vector<Record> bill;
    double costs[24];

  public:
    Solution()
    {
        for (int i = 0; i < 24; ++i) {
            cin >> costs[i];
            costs[i] /= 100.0;
        }
        int num;
        cin >> num;
        while (num--) {
            string n, s;
            int m, d, h, ms;
            (cin >> n >> m).get();
            (cin >> d).get();
            (cin >> h).get();
            cin >> ms >> s;
            bill.emplace_back(n, m, d, h, ms, s);
        }
        sort(bill.begin(), bill.end(), Less());
        for (auto it = bill.begin(); it != bill.end();) {
            auto nxt = next(it);
            it = nxt == bill.end() || it->name != nxt->name || it->status == "off-line" || nxt->status == "on-line"
                     ? bill.erase(it)
                     : next(nxt);
        }
    }

    void printResult() const
    {
        cout << setfill('0') << fixed << setprecision(2);
        int i = 0, j = 1, k = bill.size();
        double m = 0.0;
        while (i < k) {
            auto amount = getCost(bill[i], bill[j]);
            m += amount.second;
            if (i == 0 || bill[i].name != bill[i - 2].name)
                cout << bill[i].name << ' ' << setw(2) << bill[i].month << '\n';
            cout << setw(2) << bill[i].day << ':' << setw(2) << bill[i].hour << ':' << setw(2) << bill[i].minute << ' '
                 << setw(2) << bill[j].day << ':' << setw(2) << bill[j].hour << ':' << setw(2) << bill[j].minute << ' '
                 << amount.first << " $" << amount.second << '\n';
            if (i + 2 == k || bill[i].name != bill[i + 2].name) {
                cout << "Total amount: $" << m;
                if (i + 2 < k) {
                    m = 0.0;
                    cout << '\n';
                }
            }
            i += 2, j += 2;
        }
    }

  private:
    struct Less {
        bool operator()(const Record &x, const Record &y) const
        {
            int cmp = x.name.compare(y.name);
            return cmp < 0 ||
                   cmp == 0 && (x.day < y.day ||
                                x.day == y.day && (x.hour < y.hour || x.hour == y.hour && x.minute < y.minute));
        }
    };

    pair<int, double> getCost(const Record &x, const Record &y) const
    {
        int rtime = y.minute - x.minute + 60 * (y.hour - x.hour) + 1440 * (y.day - x.day);
        double rcost = 0.0;
        int hbeg = x.hour, dbeg = x.day;
        if (rtime < 60) {
            if (x.hour == y.hour) {
                rcost = (y.minute - x.minute) * costs[x.hour];
            } else {
                rcost = (60 - x.minute) * costs[x.hour] + y.minute * costs[y.hour];
            }
        } else {
            rcost = (60 - x.minute) * costs[x.hour] + y.minute * costs[y.hour];
            hbeg == 23 ? ++dbeg, hbeg = 0 : ++hbeg;
            while (dbeg != y.day || hbeg != y.hour) {
                rcost += 60 * costs[hbeg];
                hbeg == 23 ? ++dbeg, hbeg = 0 : ++hbeg;
            }
        }
        return make_pair(rtime, rcost);
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
