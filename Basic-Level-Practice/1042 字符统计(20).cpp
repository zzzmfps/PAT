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
    int record[128]{};

  public:
    Solution()
    {
        string tmp;
        getline(cin, tmp);
        for (const auto c : tmp) ++record[c];
        for (int i = 65; i < 91; ++i) record[i + 32] += record[i];
    }

    void printResult()
    {
        int letter, maxNum = 0;
        for (int i = 97; i < 123; ++i)
            if (record[i] > maxNum) {
                maxNum = record[i];
                letter = i;
            }
        cout << char(letter) << ' ' << maxNum;
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
