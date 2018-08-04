#include <iostream>
#include <queue>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    int n, m, root = 1;
    vector<int> *list;

  public:
    Solution()
    {
        cin >> n >> m;
        list = new vector<int>[n + 1];
        for (int i = 0, num, c; i < m; ++i) {
            cin >> num >> c;
            list[num].resize(c);
            while (c--) cin >> list[num][c];
        }
    }

    void getLargestGeneration()
    {
        int count, layer = 0;
        int maxCount = 0, maxLayer;
        queue<int> tmp;
        tmp.push(root);
        while (!tmp.empty()) {
            ++layer, count = tmp.size();
            if (count > maxCount) {
                maxCount = count;
                maxLayer = layer;
            }
            for (int i = count; i > 0; --i) {
                int x = tmp.front();
                tmp.pop();
                for (const auto y : list[x]) tmp.push(y);
            }
        }
        cout << maxCount << ' ' << maxLayer;
    }
};

int main(void)
{
    Solution s;
    s.getLargestGeneration();
    return 0;
}
