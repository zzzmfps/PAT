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
    static const int maxn = 10001;  // no more than 10^4, NOT 104.
    int birds[maxn];
    int counts[maxn]{};
    bool exist[maxn]{};

  public:
    Solution()
    {
        for (int i = 1; i < maxn; ++i) birds[i] = i;
        int n;
        cin >> n;
        for (int i = 0, k, x; i < n; ++i) {
            cin >> k >> x;
            exist[x] = true;
            for (int j = 1, y; j < k; ++j) {
                cin >> y;
                setUnion(x, y);
                exist[y] = true;
            }
        }
        for (int i = 1; i < maxn; ++i)
            if (exist[i]) ++counts[findFather(i)];
    }

    void queries()
    {
        int x = 0, y = 0;
        for (int i = 1; i < maxn; ++i)
            if (exist[i] && counts[i] > 0) ++x, y += counts[i];
        cout << x << ' ' << y << '\n';

        cin >> x;
        for (int i = 0, j, k; i < x; ++i) {
            cin >> j >> k;
            cout << (findFather(j) == findFather(k) ? "Yes" : "No") << '\n';
        }
    }

  private:
    int findFather(int x)
    {
        int y = x;
        while (birds[x] != x) x = birds[x];
        while (birds[y] != y) {
            int z = y;
            y = birds[y];
            birds[z] = x;
        }
        return x;
    }

    void setUnion(int a, int b)
    {
        int faA = findFather(a), faB = findFather(b);
        if (faA != faB) birds[faA] = faB;
    }
};

int main(void)
{
    Solution s;
    s.queries();
    return 0;
}
