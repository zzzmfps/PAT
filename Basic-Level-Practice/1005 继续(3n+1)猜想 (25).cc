#include <algorithm>
#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    // -1: temp important, 0: not mentioned yet, 1: not important
    int marks[10000]{};  // may larger than 100 while calculating 3n + 1
    int *record;
    int n;

  public:
    Solution()
    {
        cin >> n;
        record = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> record[i];
            int tmp = record[i];
            if (marks[tmp] > 0) continue;
            marks[tmp] = -1;
            while ((tmp = (tmp & 1 ? 3 * tmp + 1 : tmp) / 2) > 1) {
                int start = marks[tmp];
                if (start <= 0) marks[tmp] = 1;
                if (start != 0) break;
            }
        }
        sort(record, record + n, greater<int>());
    }

    void printImportantNumber()
    {
        int count = 0;
        for (int i = 0; i < n; ++i)
            if (marks[record[i]] < 0) cout << (count++ ? " " : "") << record[i];
    }
};

int main(void)
{
    Solution s;
    s.printImportantNumber();
    return 0;
}
