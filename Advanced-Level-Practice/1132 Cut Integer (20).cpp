#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
    void cutInteger()
    {
        int n;
        cin >> n;
        while (n--) {
            int z;
            cin >> z;
            int k = pow(10, int(log10(z) + 1) / 2);
            int a = z / k, b = z % k;
            if (a * b == 0 || z % (a * b) != 0) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        }
    }
};

int main(void)
{
    Solution s;
    s.cutInteger();
    return 0;
}
