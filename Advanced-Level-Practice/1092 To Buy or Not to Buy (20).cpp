#include <iostream>
#include <unordered_map>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    bool isMissed = false;
    string bead1, bead2;
    unordered_map<char, int> count1, count2;

  public:
    Solution()
    {
        cin >> bead1 >> bead2;
        for (const auto b : bead1) ++count1[b];
        for (const auto b : bead2) ++count2[b];
    }

    void check()
    {
        int misses = 0;
        for (const auto &c2 : count2) {
            if (!isMissed && c2.second > count1[c2.first]) isMissed = true;
            if (isMissed) misses += max(c2.second - count1[c2.first], 0);
        }
        if (isMissed) {
            cout << "No " << misses;
        } else {
            cout << "Yes " << bead1.size() - bead2.size();
        }
    }
};

int main(void)
{
    Solution s;
    s.check();
    return 0;
}
