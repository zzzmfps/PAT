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
    string original;
    bool delims[128]{};

  public:
    Solution()
    {
        string tmp;
        getline(cin, original);
        getline(cin, tmp);
        for (const auto c : tmp) delims[c] = true;
    }

    void outputWithDelims()
    {
        for (const auto c : original)
            if (!delims[c]) cout << c;
    }
};

int main(void)
{
    Solution s;
    s.outputWithDelims();
    return 0;
}
