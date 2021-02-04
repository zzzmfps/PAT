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
    int teams[1000]{};

  public:
    Solution()
    {
        int n, team, score;
        cin >> n;
        while (n--) {
            cin >> team;
            while (cin.get() != ' ') continue;
            cin >> score;
            teams[team] += score;
        }
    }
    
    void printMax()
    {
        int team, score;
        for (int i = 0; i < 1000; ++i)
            if (teams[i] > score) {
                team = i;
                score = teams[i];
            }
        cout << team << ' ' << score;
    }
};

int main(void)
{
    Solution s;
    s.printMax();
    return 0;
}
