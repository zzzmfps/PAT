#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int n, m;
    vector<vector<int>> answers, wrong;

public:
    Solution()
    {
        cin >> n >> m;
        answers.resize(m);
        wrong.resize(m);
        for (int i = 0; i < m; ++i) {
            int score, option, correct;
            cin >> score >> option >> correct;
            answers[i].resize(option + 2);
            wrong[i].resize(option);
            answers[i][0] = correct;
            answers[i].back() = score;
            while (correct--) {
                char c;
                cin >> c;
                answers[i][c - 96] = 1;
            }
        }
    }

    void check()
    {
        int count = 0;
        while (n--) {
            double score = 0.0;
            for (int i = 0, x; i < m; ++i) {
                cin.ignore(0x7FFFFFFF, '(');
                cin >> x;
                bool isEqual = (x == answers[i][0]), isWrong = (x > answers[i][0]);
                char c;
                cin >> c;
                for (int j = 1, idx = answers[i].size() - 1; j < idx; ++j) {
                    bool f1 = (j == c - 96), f2 = (answers[i][j] == 1);
                    if (f1 != f2) {
                        if (f1) isWrong = true;
                        wrong[i][j - 1] += 1;
                        count = max(count, wrong[i][j - 1]);
                    }
                    if (f1 && --x) cin >> c;
                }
                score += (isWrong ? 0 : isEqual ? answers[i].back() : answers[i].back() / 2.0);
            }
            cout << fixed << setprecision(1) << score << '\n';
        }
        if (count == 0) {
            cout << "Too simple";
        } else {
            for (int i = 0; i < m; ++i) {
                for (int j = 0, size = wrong[i].size(); j < size; ++j)
                    if (wrong[i][j] == count) cout << count << ' ' << i + 1 << '-' << char(j + 97) << '\n';
            }
        }
    }
};

int main(void)
{
    Solution s;
    s.check();
    return 0;
}
