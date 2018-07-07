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
    int n, m;
    int coins[501]{};

  public:
    Solution()
    {
        cin >> n >> m;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            ++coins[tmp];
        }
    }

    void printSolution()
    {
        int left = 1, right = 500;
        while (left <= right) {
            while (left <= right && !coins[left]) ++left;
            while (left <= right && !coins[right]) --right;
            int tmp = left + right;
            if (tmp == m) {
                if (left == right && coins[left] == 1) break;
                cout << left << ' ' << right;
                return;
            } else if (tmp < m) {
                ++left;
            } else {
                --right;
            }
        }
        cout << "No Solution";
    }
};

int main(void)
{
    Solution s;
    s.printSolution();
    return 0;
}
