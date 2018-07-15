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
    static const int up = 6, down = 4, stay = 5;

  public:
    Solution() {}

    int getTotalCostTime()
    {
        int n, tmp, lastFloor = 0, res = 0;
        cin >> n;
        while (n--) {
            cin >> tmp;
            res += stay + (tmp > lastFloor ? up * (tmp - lastFloor) : down * (lastFloor - tmp));
            lastFloor = tmp;
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    cout << s.getTotalCostTime();
    return 0;
}
