#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
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
    struct Car {
        string plate, status;
        int second = 0;
    };
    int num, queries, ltime = 0;
    vector<Car> record;
    map<string, int> lplate;

  public:
    Solution()
    {
        cin >> num >> queries;
        record.resize(num);  // performs better than reserve + push_back
        for (int i = 0; i < num; ++i) {
            cin >> record[i].plate;
            record[i].second = time2second();
            cin >> record[i].status;
        }

        sort(record.begin(), record.end(),
             [](const Car &x, const Car &y) { return x.plate < y.plate || x.plate == y.plate && x.second < y.second; });
        int i2 = 0;
        vector<Car> tmp(num);  // same with tmp.resize(num);
        for (int i1 = 0, j1 = 1, j2 = 1; j1 < num;) {
            if (record[i1].plate == record[j1].plate && record[i1].status == "in" && record[j1].status == "out") {
                lplate[record[i1].plate] += record[j1].second - record[i1].second;
                ltime = max(ltime, lplate[record[i1].plate]);
                tmp[i2] = move(record[i1]);
                tmp[j2] = move(record[j1]);
                i1 += 2, i2 += 2, j1 += 2, j2 += 2;
            } else {
                i1 += 1, j1 += 1;
            }
        }
        record.swap(tmp);
        record.resize((num = i2));
    }

    void response()
    {
        sort(record.begin(), record.end(), [](const Car &x, const Car &y) { return x.second < y.second; });
        int curNum = 0, curIndex = 0, query;
        while (queries--) {
            query = time2second();
            while (curIndex < num) {
                if (record[curIndex].second > query) break;
                curNum += record[curIndex++].status == "in" ? 1 : -1;
            }
            cout << curNum << '\n';
        }
        for (const auto &l : lplate)
            if (l.second == ltime) cout << l.first << ' ';
        cout << setfill('0') << setw(2) << ltime / 3600 << ':' << setw(2) << ltime % 3600 / 60 << ':' << setw(2)
             << ltime % 60;
    }

  private:
    int time2second() const
    {
        int tmp, sum = 0;
        for (int i = 0; i < 3; ++i) {
            (cin >> tmp).get();
            sum = sum * 60 + tmp;
        }
        return sum;
    }
};

int main(void)
{
    Solution s;
    s.response();
    return 0;
}
