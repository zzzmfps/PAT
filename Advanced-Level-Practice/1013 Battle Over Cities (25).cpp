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
    int cities, highways, checks;
    vector<int> *connects;

  public:
    Solution()
    {
        cin >> cities >> highways >> checks;
        connects = new vector<int>[cities + 1] {};
        for (int i = 0, c1, c2; i < highways; ++i) {
            cin >> c1 >> c2;
            connects[c1].push_back(c2);
            connects[c2].push_back(c1);
        }
    }

    void query()
    {
        for (int i = 0, city; i < checks; ++i) {
            cin >> city;
            cout << max(0, getNumber(city) - 1) << '\n';
        }
        delete[] connects;
    }

  private:
    int getNumber(int city)
    {
        int ret = 0;
        bool *isVisited = new bool[cities + 1]{};
        isVisited[city] = true;

        for (int x = 1; x <= cities; ++x) {
            if (x == city || isVisited[x]) continue;
            ++ret, isVisited[x] = true;

            queue<int> tmp;
            tmp.push(x);
            while (!tmp.empty()) {
                int y = tmp.front();
                tmp.pop();
                for (const auto z : connects[y])
                    if (!isVisited[z]) {
                        isVisited[z] = true;
                        tmp.push(z);
                    }
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    s.query();
    return 0;
}
