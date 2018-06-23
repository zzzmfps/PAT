#include <algorithm>
#include <iostream>
#include <unordered_map>
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
    struct Student {
        int id, score;
        Student(int i, int s) : id(i), score(s) {}
    };
    struct Greater {
        bool operator()(const Student &x, const Student &y) const { return x.score > y.score; }
    };
    vector<Student> tmpRank[4];
    unordered_map<int, pair<int, char>> bestRank;
    const char types[4]{'A', 'C', 'M', 'E'};
    int num, check;

  public:
    Solution()
    {
        cin >> num >> check;
        int id, clang, math, eng;
        for (int i = 0; i < num; ++i) {
            cin >> id >> clang >> math >> eng;
            tmpRank[0].emplace_back(id, clang + math + eng);
            tmpRank[1].emplace_back(id, clang);
            tmpRank[2].emplace_back(id, math);
            tmpRank[3].emplace_back(id, eng);
        }
    }

    void getRank()
    {
        for (int i = 0; i < 4; ++i) {
            auto &tr = tmpRank[i];
            sort(tr.begin(), tr.end(), Greater());
            int r = 1, s = tr[0].score;
            for (int k = 0; k < num; ++k) {
                if (s > tr[k].score) {
                    r = k + 1;
                    s = tr[k].score;
                }
                auto it = bestRank.find(tr[k].id);
                if (it == bestRank.end() || it->second.first > r) bestRank[tr[k].id] = make_pair(r, types[i]);
            }
        }
    }

    void getResult()
    {
        int checkID;
        for (int i = 0; i < check; ++i) {
            cin >> checkID;
            cout << (i > 0 ? "\n" : "");
            if (bestRank.find(checkID) != bestRank.end()) {
                cout << bestRank[checkID].first << ' ' << bestRank[checkID].second;
            } else {
                cout << "N/A";
            }
        }
    }
};

int main(void)
{
    Solution s;
    s.getRank();
    s.getResult();
    return 0;
}
