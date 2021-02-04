#include <algorithm>
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
    static const int MAXN = 175759;
    int n, k;
    vector<vector<int>> list;

  public:
    Solution()
    {
        list.resize(MAXN);
        cin >> n >> k;
        int index, num;
        string name;
        while (k--) {
            cin >> index >> num;
            while (num--) {
                cin >> name;
                auto &stu = list[hash(name)];
                stu.push_back(index);
            }
        }
    }
    void query()
    {
        string name;
        while (n--) {
            cin >> name;
            cout << name;
            auto &stu = list[hash(name)];
            cout << ' ' << stu.size();
            sort(stu.begin(), stu.end());
            for (auto it = stu.begin(); it != stu.end(); ++it) cout << ' ' << *it;
            cout << '\n';
        }
    }

  private:
    int hash(string name)
    {
        int res = 0;
        for (int i = 0; i < 3; ++i) res = res * 26 + name[i] - 'A';
        return res * 10 + name[3] - '0';
    }
};

int main(void)
{
    Solution s;
    s.query();
    return 0;
}
