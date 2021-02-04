#include <cmath>
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
    int msize, n, elem;
    bool *isInserted;

  public:
    Solution()
    {
        cin >> msize >> n;
        if (msize < 2) {
            msize = 2;
        } else if (msize > 3) {
            for (int i = (msize & 1 ? msize : msize + 1); true; i += 2) {
                int limit = sqrt(i) + 1, j;
                for (j = 3; j <= limit; j += 2)
                    if (i % j == 0) break;
                if (j > limit) {
                    msize = i;
                    break;
                }
            }
        }
        isInserted = new bool[msize]{};
    }

    void tryInsertElement()
    {
        while (n--) {
            cin >> elem;
            int beg = elem % msize, i;
            if (!isInserted[beg]) {
                isInserted[beg] = true;
                cout << beg << (n ? " " : "");
                continue;
            }
            for (i = 1; i < msize; ++i) {
                int j = (beg + i * i) % msize;
                if (!isInserted[j]) {
                    isInserted[j] = true;
                    cout << j << (n ? " " : "");
                    break;
                }
            }
            if (i == msize) cout << '-' << (n ? " " : "");
        }
    }
};

int main(void)
{
    Solution s;
    s.tryInsertElement();
    return 0;
}
