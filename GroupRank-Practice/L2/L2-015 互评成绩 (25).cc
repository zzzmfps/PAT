#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<double> scores; // Wrong Answer when using set<double>
    int m;

public:
    Solution()
    {
        int n, k;
        cin >> n >> k >> m;
        m = min(m, n);
        for (int i = 0; i < n; ++i) {
            int _sum = 0, _min = 100, _max = 0, score;
            for (int j = 0; j < k; ++j) {
                cin >> score;
                _sum += score;
                _min = min(_min, score);
                _max = max(_max, score);
            }
            scores.push_back(double(_sum - _min - _max) / (k - 2));
        }
        sort(scores.begin(), scores.end());
    }

    void printKScores()
    {
        auto it = prev(scores.end(), m);
        while (true) {
            cout << fixed << setprecision(3) << *(it++);
            if (it == scores.end()) break;
            cout << ' ';
        }
    }
};

int main(void)
{
    Solution s;
    s.printKScores();
    return 0;
}
