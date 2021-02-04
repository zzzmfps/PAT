#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
private:
    int n;
    unordered_map<string, pair<double, int>> records;

public:
    Solution()
    {
        (cin >> n).get();
        while (n--) {
            char level = cin.get();
            cin.ignore(0x7FFFFFFF, ' ');
            double score;
            cin >> score;
            if (level == 'B') {
                score /= 1.5;
            } else if (level == 'T') {
                score *= 1.5;
            }
            string name;
            (cin >> name).get();
            for (auto &n : name) n = tolower(n);
            if (records.find(name) == records.end()) {
                records[name] = make_pair(score, 1);
            } else {
                records[name].first += score;
                records[name].second += 1;
            }
        }
    }

    void rank()
    {
        vector<pair<string, pair<int, int>>> tmp(records.begin(), records.end());
        sort(tmp.begin(), tmp.end(),
             [](const pair<string, pair<int, int>> &x, const pair<string, pair<int, int>> &y) {
                 return x.second.first > y.second.first ||
                     x.second.first == y.second.first && x.second.second < y.second.second ||
                     x.second.first == y.second.first && x.second.second == y.second.second && x.first < y.first;
             });
        int last = 0x7FFFFFFF, r = 0, size = tmp.size();
        cout << size << '\n';
        for (int i = 0; i < size; ++i) {
            if (tmp[i].second.first < last) r = i + 1, last = tmp[i].second.first;
            cout << r << ' ' << tmp[i].first << ' ' << tmp[i].second.first << ' ' << tmp[i].second.second << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.rank();
    return 0;
}
