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
    unordered_map<string, int> m2e{{"jan", 1},  {"feb", 2},  {"mar", 3}, {"apr", 4}, {"may", 5},
                                   {"jun", 6},  {"jly", 7},  {"aug", 8}, {"sep", 9}, {"oct", 10},
                                   {"nov", 11}, {"dec", 12}, {"tret", 0}};
    unordered_map<string, int> cm2e{{"tam", 1}, {"hel", 2}, {"maa", 3}, {"huh", 4},  {"tou", 5},  {"kes", 6},
                                    {"hei", 7}, {"elo", 8}, {"syy", 9}, {"lok", 10}, {"mer", 11}, {"jou", 12}};
    string e2m[13]{"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string ce2m[13]{"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int n;

  public:
    Solution() { (cin >> n).get(); }

    void translate()
    {
        while (n--) {
            char c = cin.peek();
            c <= '9' ? earth2Mars() : mars2Earth();
        }
    }

  private:
    void earth2Mars()
    {
        int tmp;
        (cin >> tmp).get();
        if (tmp < 13) {
            cout << e2m[tmp] << '\n';
        } else if (tmp % 13 == 0) {
            cout << ce2m[tmp / 13] << '\n';
        } else {
            cout << ce2m[tmp / 13] << ' ' << e2m[tmp % 13] << '\n';
        }
    }

    void mars2Earth()
    {
        string tmp;
        cin >> tmp;
        if (cin.peek() == '\n') {
            cout << (m2e.find(tmp) != m2e.end() ? m2e[tmp] : 13 * cm2e[tmp]) << '\n';
        } else {
            int res = 13 * cm2e[tmp];
            cin >> tmp;
            cout << res + m2e[tmp] << '\n';
        }
        cin.get();
    }
};

int main(void)
{
    Solution s;
    s.translate();
    return 0;
}
