#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Time
{
  private:
    const int BEG = 28800, END = 61200;  // begin time: 8 * 3600, end time: 17 * 3600
    int sec, proc;                       // proc: minutes

  public:
    Time(int h, int m, int s, int p) : sec(3600 * h + 60 * m + s), proc(p > 60 ? 60 : p) {}

    static bool sortRule(const Time &x, const Time &y) { return x.sec < y.sec; }

    int earlierThanBegin() const { return BEG - sec; }

    bool isTooLate() const { return sec > END; }

    void process(int x = 0) { sec = max(BEG, sec + max(0, x)) + 60 * proc; }

    int operator-(const Time &y) const { return sec - y.sec; }

    void operator=(const Time &y) { sec = y.sec, proc = y.proc; }
};

class Solution
{
  private:
    int n, k;

  public:
    Solution() { cin >> n >> k; }

    double getAvgWaitTime()
    {
        vector<Time> all;
        getTime(all);
        sort(all.begin(), all.end(), Time::sortRule);
        n = distance(all.begin(), find_if(all.begin(), all.end(), [](const Time &x) { return x.isTooLate(); }));
        k = min(k, n);

        int total = 0;
        vector<Time> q;
        for (int i = 0; i < k; ++i) {
            int diff = all[i].earlierThanBegin();
            if (diff > 0) total += diff;
            all[i].process(), q.push_back(all[i]);
        }

        for (int i = k; i < n; ++i) {
            sort(q.begin(), q.end(), Time::sortRule);
            int diff = q.front() - all[i];
            if (diff > 0) total += diff;
            all[i].process(diff), q.front() = all[i];
        }

        return total / (60.0 * n);
    }

  private:
    void getTime(vector<Time> &x)
    {
        for (int i = 0, h, m, s, p; i < n; ++i) {
            (cin >> h).get();
            (cin >> m).get();
            cin >> s >> p;
            x.emplace_back(h, m, s, p);
        }
    }
};

int main(void)
{
    Solution s;
    cout << fixed << setprecision(1) << s.getAvgWaitTime();
    return 0;
}
