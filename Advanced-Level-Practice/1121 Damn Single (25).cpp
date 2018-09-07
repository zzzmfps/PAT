#include <iomanip>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    unordered_map<int, int> couples;
    set<int> singles;

  public:
    Solution()
    {
        int n;
        cin >> n;
        for (int i = 0, j, k; i < n; ++i) {
            cin >> j >> k;
            couples[j] = k;
            couples[k] = j;
        }

        cin >> n;
        for (int i = 0, j, k; i < n; ++i) {
            cin >> j;
            k = couples[j];
            auto iter = singles.find(k);
            if (iter == singles.end()) {
                singles.insert(j);
            } else {
                singles.erase(k);
            }
        }
    }

    void printResult()
    {
        cout << singles.size() << '\n' << setfill('0');
        for (auto iter = singles.begin(); iter != singles.end(); ++iter)
            cout << (iter == singles.begin() ? "" : " ") << setw(5) << *iter;
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
