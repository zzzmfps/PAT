#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    struct Question {
        int full, opts, corrects;
        string ans = "";
    };
    int n, m, *wrongs;
    Question *answers;

  public:
    Solution()
    {
        cin >> n >> m;
        wrongs = new int[m]{};

        answers = new Question[m];
        for (int i = 0; i < m; ++i) {
            cin >> answers[i].full >> answers[i].opts >> answers[i].corrects;
            char ch;
            for (int j = 0; j < answers[i].corrects; ++j) {
                cin >> ch;
                answers[i].ans += ch;
            }
            sort(answers[i].ans.begin(), answers[i].ans.end());
        }
    }

    ~Solution()
    {
        delete[] wrongs;
        delete[] answers;
    }

    void check()
    {
        int maxw = 0;
        for (int i = 0; i < n; ++i) {
            int point = 0;
            for (int j = 0, num; j < m; ++j) {
                cin.ignore(20, '(');
                cin >> num;
                if (num != answers[j].corrects) {
                    ++wrongs[j], maxw = max(maxw, wrongs[j]);
                    cin.ignore(20, ' ');
                    continue;
                }
                string tmp = "";
                char ch;
                while (num--) {
                    cin >> ch;
                    tmp += ch;
                }
                sort(tmp.begin(), tmp.end());
                if (tmp == answers[j].ans) {
                    point += answers[j].full;
                } else {
                    ++wrongs[j], maxw = max(maxw, wrongs[j]);
                }
            }
            cout << point << '\n';
        }
        if (maxw) {
            cout << maxw;
            for (int i = 0; i < m; ++i)
                if (wrongs[i] == maxw) cout << ' ' << i + 1;
        } else {
            cout << "Too simple";
        }
    }
};

int main(void)
{
    Solution s;
    s.check();
    return 0;
}
