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
    int count[101]{};

  public:
    Solution()
    {
        int n, score;
        cin >> n;
        while (n--) {
            cin >> score;
            ++count[score];
        }
    }

    void getNum()
    {
        int n, score;
        cin >> n;
        while (n--) {
            cin >> score;
            cout << count[score] << (n ? " " : "");
        }
    }
};

int main(void)
{
    Solution s;
    s.getNum();
    return 0;
}
