#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    int n;
    string *segments;

  public:
    Solution()
    {
        cin >> n;
        segments = new string[n];
        for (int i = 0; i < n; ++i) cin >> segments[i];
    }

    void recoverSmallestNum()
    {
        sort(segments, segments + n, [](const string &x, const string &y) { return x + y < y + x; });
        string res = "";
        for (int i = 0; i < n; ++i) res += segments[i];
        int notZero = 0;
        while (notZero < n && res[notZero] == '0') ++notZero;
        cout << (notZero == n ? "0" : res.substr(notZero));
    }
};

int main(void)
{
    Solution s;
    s.recoverSmallestNum();
    return 0;
}
