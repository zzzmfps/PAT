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

class Solution
{
  private:
    struct Student {
        int location;
        int score;
        string id;
        Student(int l, int s, string i) : location(l), score(s), id(i) {}
    };
    vector<Student> ranklists;
    int n;

  public:
    Solution()
    {
        int m, score;
        cin >> n;
        string id;
        for (int i = 1; i <= n; ++i) {
            cin >> m;
            ranklists.reserve(ranklists.size() + m);
            for (int j = 0; j < m; ++j) {
                cin >> id >> score;
                ranklists.emplace_back(i, score, id);
            }
        }
        sort(ranklists.begin(), ranklists.end(), [](const Student &x, const Student &y) {
            return x.score > y.score || x.score == y.score && x.id.compare(y.id) < 0;
        });
    }

    void printResult()
    {
        int lastScore = 101, finalRank = 0, idx = 0;
        int *lScore = new int[n](), *lRank = new int[n](), *lIdx = new int[n]();
        cout << ranklists.size();
        for (idx = 0; idx < ranklists.size(); ++idx) {
            int loc = ranklists[idx].location - 1;
            ++lIdx[loc];
            cout << '\n' << ranklists[idx].id;
            if (ranklists[idx].score != lastScore) {
                lRank[loc] = lIdx[loc];
                finalRank = idx + 1;
            } else if (ranklists[idx].score != lScore[loc])
                lRank[loc] = lIdx[loc];
            cout << ' ' << finalRank << ' ' << loc + 1 << ' ' << lRank[loc];
            lastScore = lScore[loc] = ranklists[idx].score;
        }
    };
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
