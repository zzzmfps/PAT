#include <iomanip>
#include <iostream>
using namespace std;

class Solution
{
public:
    void shoot()
    {
        int n;
        cin >> n;
        int id1, id2, _min = 20000, _max = 0;
        while (n--) {
            int t, tx, ty, ts;
            cin >> t >> tx >> ty;
            ts = tx * tx + ty * ty;
            if (ts < _min) {
                _min = ts;
                id1 = t;
            }
            if (ts > _max) {
                _max = ts;
                id2 = t;
            }
        }
        cout << setfill('0');
        cout << setw(4) << id1 << ' ' << setw(4) << id2;
    }
};

int main(void)
{
    Solution s;
    s.shoot();
    return 0;
}
