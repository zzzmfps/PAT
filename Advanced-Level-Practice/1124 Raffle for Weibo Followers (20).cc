#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> lottery()
    {
        int m, n, s;
        (cin >> m >> n >> s).get();
        vector<string> res;
        for (int i = 1; s <= m; ++i) {
            if (i != s) {
                cin.ignore(0x7FFFFFFF, '\n');
                continue;
            }
            string tmp;
            getline(cin, tmp);
            if (find(res.begin(), res.end(), tmp) != res.end()) {
                s += 1;
            } else {
                res.push_back(tmp);
                s += n;
            }
        }
        return res;
    }
};


int main(void)
{
    Solution s;
    vector<string> res = s.lottery();
    if (res.empty()) {
        cout << "Keep going...";
    } else {
        for (const auto &x : res) cout << x << '\n';
    }
    return 0;
}
