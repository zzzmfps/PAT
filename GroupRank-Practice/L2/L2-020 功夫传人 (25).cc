#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
private:
    int n;
    double power, decre;
    vector<vector<int>> record;
    vector<double> factors;

public:
    Solution()
    {
        cin >> n >> power >> decre;
        record.resize(n);
        factors.resize(n, 1.0);
        for (int i = 0, m; i < n; ++i) {
            cin >> m;
            if (m == 0) cin >> factors[i];
            record[i].resize(m);
            for (int j = 0; j < m; ++j) cin >> record[i][j];
        }
    }

    int allPower()
    {
        double fac = 1.0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                int cur = q.front();
                factors[cur] *= fac;
                for (int j = 0, size = record[cur].size(); j < size; ++j) q.push(record[cur][j]);
                q.pop();
            }
            fac *= (1.0 - decre / 100.0);
        }
        double _sum = 0.0;
        for (int i = 0; i < n; ++i)
            if (record[i].empty()) _sum += factors[i] * power;
        return int(_sum);
    }
};

int main(void)
{
    Solution s;
    cout << s.allPower();
    return 0;
}
