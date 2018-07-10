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
    int n, *array;
    bool isZeroWrong = false, *state;

  public:
    Solution()
    {
        cin >> n;
        array = new int[n];
        state = new bool[n]{};
        for (int i = 0; i < n; ++i) {
            cin >> array[i];
            if (i == array[i]) {
                state[i] = true;
            } else if (i == 0)
                isZeroWrong = true;
        }
    }

    int getMinSwapNum()
    {
        int i = 0, start = 1, count = 0;
        while (true) {
            if (state[i]) {
                while (start < n && state[start]) ++start;
                if (start == n) return count - isZeroWrong;
                i = start;
            } else {
                state[i] = true;
            }
            ++count, i = array[i];
        }
    }
};

int main(void)
{
    Solution s;
    cout << s.getMinSwapNum();
    return 0;
}
