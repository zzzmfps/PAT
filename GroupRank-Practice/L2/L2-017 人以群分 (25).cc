#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> vals;

public:
    Solution()
    {
        int n;
        cin >> n;
        vals.resize(n);
        for (int i = 0; i < n; ++i) cin >> vals[i];
    }

    void divide()
    {
        int n = vals.size() / 2;
        nth_element(vals.begin(), vals.begin() + n, vals.end()); // find the correct pivot
        cout << "Outgoing #: " << vals.size() - n << '\n';
        cout << "Introverted #: " << n << "\nDiff = ";
        cout << accumulate(vals.begin() + n, vals.end(), 0) - accumulate(vals.begin(), vals.begin() + n, 0);
    }
};

int main(void)
{
    Solution s;
    s.divide();
    return 0;
}
