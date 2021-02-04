#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
private:
    int n, m;
    map<string, int> rec1;  // id, score
    unordered_map<int, pair<int, int>> rec2;    // place, num, totalScore
    unordered_map<int, unordered_map<int, int>> rec3;    // date, place, num

public:
    Solution()
    {
        cin >> m >> n;
        string id;
        int score;
        while (m--) {
            cin >> id >> score;
            rec1[id] = score;
            int place = stoi(id.substr(1, 3)), date = stoi(id.substr(4, 6));
            if (rec2.find(place) == rec2.end()) {
                rec2[place] = make_pair(1, score);
            } else {
                rec2[place].first += 1;
                rec2[place].second += score;
            }
            rec3[date][place] += 1;
        }
    }

    void decode()
    {
        int type;
        for (int i = 1; i <= n; ++i) {
            cin >> type;
            cout << "Case " << i << ": " << type << ' ';
            if (type == 1) {
                string order;
                cin >> order;
                cout << order << '\n';
                auto it1 = rec1.lower_bound(order);
                order[0] += 1;
                auto it2 = rec1.lower_bound(order);
                if (it1 != it2) {
                    vector<pair<string, int>> tmp(it1, it2);
                    sort(tmp.begin(), tmp.end(),
                         [](const pair<string, int> &x, const pair<string, int> &y) {
                             return x.second > y.second || x.second == y.second && x.first < y.first;
                         });
                    for (const auto &p : tmp) cout << p.first << ' ' << p.second << '\n';
                    continue;
                }
            } else {
                int order;
                cin >> order;
                if (type == 2) {
                    cout << order << '\n';
                    if (rec2.find(order) != rec2.end()) {
                        cout << rec2[order].first << ' ' << rec2[order].second << '\n';
                        continue;
                    }
                } else {
                    cout << setw(6) << setfill('0') << order << '\n';
                    if (rec3.find(order) != rec3.end()) {
                        auto &x = rec3[order];
                        vector<pair<int, int>> tmp(x.begin(), x.end());
                        sort(tmp.begin(), tmp.end(),
                             [](const pair<int, int> &x, const pair<int, int> &y) {
                                 return x.second > y.second || x.second == y.second && x.first < y.first;
                             });
                        for (const auto &p : tmp) cout << p.first << ' ' << p.second << '\n';
                        continue;
                    }
                }
            }
            cout << "NA\n";
        }
    }
};

int main(void)
{
    Solution s;
    s.decode();
    return 0;
}
