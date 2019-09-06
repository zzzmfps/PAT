#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    void revProduct()
    {
        int x, y;
        cin >> x >> y;
        if (x * y == 0) {
            cout << 0;
        } else {
            string p = to_string(x * y);
            string r(p.rbegin(), p.rend());
            cout << r.substr(r.find_first_not_of('0'));
        }
    }
};

int main(void)
{
    Solution s;
    s.revProduct();
    return 0;
}
