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
        for (int i = 0, id, num; i < m; ++i) {
            cin >> id >> num;
            list[id].resize(num);
            while (num--) cin >> list[id][num];
        }
    }

    void countLeaves()
    {
        cout << (list[root].empty() ? '1' : '0');
        queue<int> tmp;
        for (const auto x : list[root]) tmp.push(x);
        while (!tmp.empty()) {
            int count = 0;
            for (int i = tmp.size(); i > 0; --i) {
                int x = tmp.front();
                if (list[x].empty()) ++count;
                tmp.pop();
                for (const auto y : list[x]) tmp.push(y);
            }
            cout << ' ' << count;
        }
    }
};

int main(void)
{
    Solution s;
    s.countLeaves();
    return 0;
}
