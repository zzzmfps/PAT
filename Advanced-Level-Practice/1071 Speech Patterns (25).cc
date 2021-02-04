#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    unordered_map<string, int> rec;
    pair<string, int> res{"", 0};

  public:
    Solution()
    {
        char c;
        string str = "";
        while ((c = cin.get())) {
            if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
                str += char(tolower(c));
            } else if (!str.empty()) {
                if (++rec[str] > res.second || rec[str] == res.second && str < res.first)
                    res.first = str, res.second = rec[str];
                str = "";
            }
            if (c == '\n') break;
        }
    }

    void getMostCommonWord() { cout << res.first << ' ' << res.second; }
};

int main(void)
{
    Solution s;
    s.getMostCommonWord();
    return 0;
}
