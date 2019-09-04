#include <iostream>
using namespace std;

class Solution
{
public:
    void getScores()
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            double g1 = 0.0;
            int tmp, count = -2, _min = m, _max = 0, g2;
            cin >> g2;
            for (int j = 1; j < n; ++j) {
                cin >> tmp;
                if (tmp >= 0 && tmp <= m) {
                    g1 += tmp;
                    count += 1;
                    _min = min(_min, tmp);
                    _max = max(_max, tmp);
                }
            }
            g1 = (g1 - _min - _max) / count;
            cout << int(0.5 + (g1 + g2) / 2) << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.getScores();
    return 0;
}
