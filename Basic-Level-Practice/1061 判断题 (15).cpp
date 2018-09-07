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
    int n, m, *full, *ans;

  public:
    Solution()
    {
        cin >> n >> m;
        full = new int[m];
        for (int i = 0; i < m; ++i) cin >> full[i];
        ans = new int[m];
        for (int i = 0; i < m; ++i) cin >> ans[i];
    }

    void printResult()
    {
        for (int i = 0; i < n; ++i) {
            int score = 0;
            for (int j = 0, k; j < m; ++j) {
                cin >> k;
                if (k == ans[j]) score += full[j];
            }
            cout << score << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
