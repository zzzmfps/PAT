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
    static const int ONCE = 17;
    string bigNum;
    int digit;

  public:
    Solution() { cin >> bigNum >> digit; }

    void divide()
    {
        int beg = 0, len = bigNum.size();
        string left = "";
        while (beg < len) {
            if (left == "0") {
                if (bigNum[beg] == '0') {
                    int end = beg + 1;
                    while (end < len && bigNum[end] == '0') ++end;
                    cout << string(end - beg, '0');
                    beg = end;
                }
                if (digit > bigNum[beg] - '0') cout << '0';
            }
            long long tmp = stoll(left + bigNum.substr(beg, ONCE));
            left = to_string(tmp % digit);
            cout << tmp / digit;
            beg += ONCE;
        }
        cout << ' ' << left;
    }
};

int main(void)
{
    Solution s;
    s.divide();
    return 0;
}
