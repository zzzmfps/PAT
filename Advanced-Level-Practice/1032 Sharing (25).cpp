#include <iomanip>
#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution  // input may contain useless and repeated nodes (test point 2, 5)
{
  private:
    int beg1, beg2, n, list[100000];
    bool rec[100000]{};

  public:
    Solution() { cin >> beg1 >> beg2 >> n; }

    void getCommonSuffixStartPosition()
    {
        int cur, next;
        while (n--) {
            (cin >> cur).ignore(3);
            cin >> next;
            list[cur] = next;
        }
        for (int i = beg1; i != -1; i = list[i]) rec[i] = true;
        for (int i = beg2; i != -1; i = list[i])
            if (rec[i]) {
                cout << setfill('0') << setw(5) << i;
                return;
            }
        cout << "-1";
    }
};

int main(void)
{
    Solution s;
    s.getCommonSuffixStartPosition();
    return 0;
}
