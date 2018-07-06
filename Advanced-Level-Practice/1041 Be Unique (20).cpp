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
    int j = 0;
    int *order;
    int counts[10000];

  public:
    Solution()
    {
        int n, tmp;
        cin >> n;
        order = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (++counts[tmp] == 1) order[j++] = tmp;
        }
    }

    void findUnique()
    {
        for (int i = 0; i < j; ++i)
            if (counts[order[i]] == 1) {
                cout << order[i];
                return;
            }
        cout << "None";
    }
};

int main(void)
{
    Solution s;
    s.findUnique();
    return 0;
}
