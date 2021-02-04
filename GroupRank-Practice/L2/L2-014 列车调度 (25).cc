#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> rails;

public:
    int dispatch()
    { // simple simulation, by descending order
        int n;
        cin >> n;
        for (int i = 0, j; i < n; ++i) {
            cin >> j;
            auto it = upper_bound(rails.begin(), rails.end(), j);
            if (it == rails.end()) {
                rails.push_back(j);
            } else {
                *it = j;
            }
        }
        return rails.size();
    }
};

int main(void)
{
    Solution s;
    cout << s.dispatch();
    return 0;
}
