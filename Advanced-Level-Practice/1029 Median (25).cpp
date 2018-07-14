#include <iostream>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution  // AC but only gives me 16/25 scores, why???
{
  private:
    int n1, n2;
    vector<int> seq;

  public:
    Solution()
    {
        cin >> n1;
        seq.resize(n1);
        for (int i = 0; i < n1; ++i) cin >> seq[i];

        cin >> n2;
        seq.resize((n1 + n2 + 1) / 2);
        for (int i = seq.size() - 1; i >= n1; --i) cin >> seq[i];

        int mark = n1 - 1, tmp;
        for (int i = n1 + n2 - seq.size(); i > 0; --i, --mark) {
            cin >> tmp;
            if (tmp >= seq[mark]) break;
            seq[mark] = tmp;
            if (mark == 0) break;
        }
        cout << max(max(seq[mark], seq[mark + 1]), seq.back());
    }
};

int main(void)
{
    Solution s;
    return 0;
}
