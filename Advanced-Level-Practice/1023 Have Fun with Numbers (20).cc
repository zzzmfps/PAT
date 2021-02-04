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
    string num, doubled = "";
    int record1[10]{}, record2[10]{};

  public:
    Solution() { cin >> num; }

    void checkDoubledNum()
    {
        int i, carry = 0;
        for (i = num.size() - 1; i >= 0; --i) {
            ++record1[num[i] - '0'];
            int tmp = carry + (num[i] - '0') * 2;
            carry = tmp / 10;
            doubled = to_string(tmp - 10 * carry) + doubled;
            ++record2[doubled[0] - '0'];
        }
        if (carry > 0) {
            doubled = to_string(carry) + doubled;
            ++record2[carry];
        }
        for (i = 0; i < 10; ++i)
            if (record1[i] != record2[i]) {
                cout << "No\n";
                break;
            }
        if (i == 10) cout << "Yes\n";
        cout << doubled;
    }
};

int main(void)
{
    Solution s;
    s.checkDoubledNum();
    return 0;
}
