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
    int n, k;
    vector<vector<string>> list;

  public:
    Solution()
    {
        cin >> n >> k;
        list.resize(k + 1);
        int c, index;
        string name;
        while (n--) {
            cin >> name >> c;
            while (c--) {
                cin >> index;
                list[index].push_back(name);
            }
        }
    }

    void printByCourses()
    {
        for (int i = 1; i <= k; ++i) {
            auto &li = list[i];
            cout << i << ' ' << li.size() << '\n';
            sort(li.begin(), li.end());
            for (auto it = li.begin(); it != li.end(); ++it) cout << *it << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.printByCourses();
    return 0;
}
