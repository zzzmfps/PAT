#include <iostream>
#include <map>
#include <utility>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    map<int, pair<string, string>> record;

  public:
    Solution()
    {
        int num, grade;
        string name, id;
        cin >> num;
        for (int i = 0; i < num; ++i) {
            cin >> name >> id >> grade;
            record[-grade] = make_pair(name, id);
        }
    }

    void getRank()
    {
        int left, right;
        cin >> left >> right;
        auto it1 = record.lower_bound(-right), it2 = record.upper_bound(-left);
        if (it1 == it2) {
            cout << "NONE";
        } else {
            cout << it1->second.first << ' ' << it1->second.second;
            while (++it1 != it2) cout << '\n' << it1->second.first << ' ' << it1->second.second;
        }
    }
};

int main(void)
{
    Solution s;
    s.getRank();
    return 0;
}
