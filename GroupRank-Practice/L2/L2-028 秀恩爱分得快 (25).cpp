#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution // easily meets TLE on testcase 4
{
private:
    int n, m;
    vector<unordered_set<int>> pictures[2]; // (female, male) in i-th pictures

public:
    Solution()
    {
        cin >> n >> m;
        pictures[0].resize(m), pictures[1].resize(m);
        for (int i = 0, k; i < m; ++i) {
            (cin >> k).get();
            for (int j = 0, p; j < k; ++j) {
                bool _isFemale = (cin.peek() == '-'); // there are '0' and '-0'
                (cin >> p).get();
                pictures[_isFemale ? 0 : 1][i].insert(abs(p));
            }
        }
    }

    void checkLovers()
    {
        string x, y; // may occur '-0'
        cin >> x >> y;
        bool x_female = (x[0] == '-');                  // is x female, y is opposite
        int x_abs = abs(stoi(x)), y_abs = abs(stoi(y)); // use as index
        double x_max = 0.0, y_max = 0.0;
        vector<double> x_rel(n), y_rel(n);
        for (int i = 0; i < m; ++i) {
            auto &x_tmp = pictures[x_female ? 0 : 1][i];
            auto &y_tmp = pictures[!x_female ? 0 : 1][i];
            double factor = 1.0 / (x_tmp.size() + y_tmp.size());
            if (x_tmp.find(x_abs) != x_tmp.end())
                for (auto v : y_tmp) x_max = max(x_max, x_rel[v] += factor);
            if (y_tmp.find(y_abs) != y_tmp.end())
                for (auto v : x_tmp) y_max = max(y_max, y_rel[v] += factor);
        }
        if (x_max == y_max && x_max == x_rel[y_abs]) {
            cout << x << ' ' << y;
        } else {
            string prefix[2] = {" ", " "};
            prefix[x_female ? 1 : 0].push_back('-');
            for (int i = 0; i < n; ++i)
                if (x_rel[i] == x_max) cout << x << prefix[0] << i << '\n';
            for (int i = 0; i < n; ++i)
                if (y_rel[i] == y_max) cout << y << prefix[1] << i << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.checkLovers();
    return 0;
}
