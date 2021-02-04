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
    int n;
    string str;

  public:
    Solution()
    {
        cin >> n;
        while (n--) {
            cin >> str;
            int part[3]{}, type = 0;
            for (const auto s : str) {
                if (s == 'A') {
                    ++part[type];
                } else if (s == 'P' && type == 0) {
                    type = 1;
                } else if (s == 'T' && type == 1) {
                    type = 2;
                } else {
                    type = 3;
                    break;
                }
            }
            if (type == 2 && part[1] && part[0] * part[1] == part[2]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
};

int main(void)
{
    Solution s;
    return 0;
}
