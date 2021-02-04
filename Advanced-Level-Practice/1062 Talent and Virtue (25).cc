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
        int virtueGrade;
        int talentGrade;
        int totalGrade;
        string id;
        Student(string &i, int v, int t) : id(i), virtueGrade(v), talentGrade(t), totalGrade(v + t) {}
    };
    struct rankCmp {
        bool operator()(const Student &x, const Student &y)
        {
            return x.totalGrade > y.totalGrade || x.totalGrade == y.totalGrade && x.virtueGrade > y.virtueGrade ||
                   x.totalGrade == y.totalGrade && x.virtueGrade == y.virtueGrade && x.id.compare(y.id) < 0;
        }
    };
    vector<Student> ranks[4];
    int size;

  public:
    Solution()
    {
        int n, l, h;
        cin >> n >> l >> h;
        size = n;
        while (n--) {
            string tmpID;
            int tmpVirtue, tmpTalent, type;
            cin >> tmpID >> tmpVirtue >> tmpTalent;
            if (tmpVirtue >= l && tmpTalent >= l) {
                if (tmpVirtue >= h && tmpTalent >= h) {
                    type = 0;
                } else if (tmpVirtue >= h) {
                    type = 1;
                } else if (tmpVirtue >= tmpTalent && tmpTalent < h) {
                    type = 2;
                } else {
                    type = 3;
                }
                ranks[type].emplace_back(tmpID, tmpVirtue, tmpTalent);
            } else {
                --size;
            }
        }
        for (int i = 0; i < 4; ++i) sort(ranks[i].begin(), ranks[i].end(), rankCmp());
    }

    void printResult()
    {
        cout << size;
        for (int i = 0; i < 4; ++i)
            for (const auto &x : ranks[i]) cout << '\n' << x.id << ' ' << x.virtueGrade << ' ' << x.talentGrade;
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
