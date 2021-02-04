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
    int record[75]{};
    string supposed, real;

  public:
    Solution()
    {
        cin >> supposed >> real;
        for (const auto r : real) record[r - 48] += 1;
    }

    void getBrokens()
    {
        string broken = "";
        for (const auto s : supposed)
            if (!record[s - 48]--) {
                if (s >= 'A' && s <= 'Z') {
                    if (record[s - 16] >= 0) broken += char(s);
                } else if (s >= 'a' && s <= 'z') {
                    if (record[s - 80] >= 0) broken += char(s - 32);
                } else {
                    broken += s;
                }
            }
        cout << broken;
    }
};

int main(void)
{
    Solution s;
    s.getBrokens();
    return 0;
}
