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
    int n, maxLevel;
    vector<int> *users;

  public:
    Solution()
    {
        cin >> n >> maxLevel;
        users = new vector<int>[n + 1] {};
        for (int i = 1, k; i <= n; ++i) {
            cin >> k;
            for (int j = 0, tmp; j < k; ++j) {
                cin >> tmp;
                users[tmp].push_back(i);
            }
        }
    }

    void query()
    {
        int k, id;
        cin >> k;
        for (int i = 0; i < k; ++i) {
            cin >> id;
            cout << getPotentialForwards(id) << '\n';
        }
        delete[] users;
    }

  private:
    int getPotentialForwards(int id)
    {
        int res = -1, level = 0;
        bool *record = new bool[n + 1]{};
        record[id] = true;
        queue<int> tmp;
        tmp.push(id);

        while (!tmp.empty() && level <= maxLevel) {
            int size = tmp.size();
            res += size, ++level;
            for (int i = 0, x; i < size; ++i) {
                x = tmp.front();
                tmp.pop();
                for (const auto y : users[x])
                    if (!record[y]) {
                        tmp.push(y);
                        record[y] = true;
                    }
            }
        }
        delete[] record;
        return res;
    }
};

int main(void)
{
    Solution s;
    s.query();
    return 0;
}
