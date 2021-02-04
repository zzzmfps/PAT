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
    bool record[128]{};  // 43('+') ~ 65('A') ~ 90('Z') ~ 122('_')
    string supposed;

  public:
    Solution()
    {
        string brokens;
        getline(cin, brokens);  // first line may be empty
        cin >> supposed;
        for (const auto b : brokens) {
            record[b] = true;
            if (b >= 65 && b <= 90) record[b + 32] = true;
        }
    }

    void getOutput()
    {
        for (const auto s : supposed) {
            if (record[s] || record[43] && s >= 65 && s <= 90) continue;
            cout << s;
        }
        cout << '\n';
    }
};

int main(void)
{
    Solution s;
    s.getOutput();
    return 0;
}
