#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
private:
    int n, g, k, total = 0;
    vector<pair<string, int>> scores; // mail, score

public:
    Solution()
    {
        cin >> n >> g >> k;
        scores.resize(n);
        for (int i = 0, s; i < n; ++i) {
            cin >> scores[i].first >> scores[i].second;
            if (scores[i].second >= g) {
                total += 50;
            } else if (scores[i].second >= 60) {
                total += 20;
            }
        }
        sort(scores.begin(), scores.end(), [](const pair<string, int> &x, const pair<string, int> &y) {
            return x.second > y.second || x.second == y.second && x.first < y.first;
        });
    }

    void rank()
    {
        cout << total << '\n';
        int r = 0, score = 101;
        for (int i = 0; i < scores.size(); ++i) {
            if (scores[i].second < score) r = i + 1, score = scores[i].second;
            if (r > k) break;
            cout << r << ' ' << scores[i].first << ' ' << scores[i].second << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.rank();
    return 0;
}
