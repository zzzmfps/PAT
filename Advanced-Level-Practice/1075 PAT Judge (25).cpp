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

class Solution
{
  private:
    struct SortRule {
        bool operator()(const vector<int> &x, const vector<int> &y) const
        {
            int flag = x.size() - 2;
            return x[1] > y[1] ||
                   x[1] == y[1] && (x.back() > y.back() || x.back() == y.back() && (x[flag] > y[flag] || x[0] < y[0]));
        }
    };
    int users, problems, submissions;
    vector<int> *scores;
    vector<int> full;

  public:
    Solution()
    {
        cin >> users >> problems >> submissions;

        scores = new vector<int>[users]();
        for (int i = 0; i < users; ++i) {
            scores[i].assign(problems + 4, -1);  // -1 for never submit
            scores[i][0] = i + 1;                // id
            // total scores, partially solved one, perfectly solved
            scores[i][1] = scores[i][problems + 2] = scores[i][problems + 3] = 0;
        }

        full.resize(problems);
        for (int i = 0; i < problems; ++i) cin >> full[i];

        int id, no, sc;
        for (int i = 0; i < submissions; ++i) {
            cin >> id >> no >> sc;
            // user whose submission can pass the compiler should be output,
            // even it doesn't get any points from the submission.
            if (sc >= 0) scores[id - 1][problems + 2] = 1;
            auto &cor = scores[id - 1][no + 1];
            if (sc == full[no - 1] && sc != cor) scores[id - 1].back() += 1;
            cor = max(cor, max(0, sc));
        }
        for (int i = 0; i < users; ++i)
            for (int j = 1; j <= problems; ++j)
                if (scores[i][j + 1] > 0) scores[i][1] += scores[i][j + 1];
        sort(scores, scores + users, SortRule());
    }

    void printRankList() const
    {
        int lastScore = 0x7FFFFFFF, rank = 0;
        cout << setfill('0');
        for (int i = 0; i < users; ++i) {
            if (scores[i][problems + 2] == 0) break;
            if (scores[i][1] < lastScore) {
                lastScore = scores[i][1];
                rank = i + 1;
            }
            cout << (i ? "\n" : "") << rank << ' ' << setw(5) << scores[i][0] << ' ' << scores[i][1];
            for (int j = 1; j <= problems; ++j) {
                cout << ' ';
                scores[i][j + 1] == -1 ? cout << "-" : cout << scores[i][j + 1];
            }
        }
    }
};

int main(void)
{
    Solution s;
    s.printRankList();
    return 0;
}
