#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

struct Scores
{
    int gp = -1, gmid = -1, gfinal = -1, g;
    void setG()
    {
        if (gmid > gfinal) {
            g = int(0.5 + 0.4 * gmid + 0.6 * gfinal);
        } else {
            g = gfinal;
        }
    }
};

class Solution
{
private:
    unordered_map<string, Scores> record;

public:
    Solution()
    {
        int onlines, mids, finals;
        cin >> onlines >> mids >> finals;
        string name;
        int s;
        while (onlines--) {
            cin >> name >> s;
            record[name].gp = s;
        }
        while (mids--) {
            cin >> name >> s;
            record[name].gmid = s;
        }
        while (finals--) {
            cin >> name >> s;
            record[name].gfinal = s;
            record[name].setG();
        }
    }

    void passed()
    {
        vector<pair<string, Scores>> tmp(record.begin(), record.end());
        sort(tmp.begin(), tmp.end(),
             [](const pair<string, Scores> &x, const pair<string, Scores> &y) {
                 return x.second.g > y.second.g || x.second.g == y.second.g && x.first < y.first;
             });
        for (auto &p : tmp) {
            if (p.second.g < 60) break;
            if (p.second.gp < 200) continue;
            cout << p.first << ' ';
            cout << p.second.gp << ' ' << p.second.gmid << ' ' << p.second.gfinal << ' ' << p.second.g << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.passed();
    return 0;
}
