#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    void missingNumber()
    {
        int n, v;
        cin >> n;
        set<int> tmp;
        while (n--) {
            cin >> v;
            if (v > 0) tmp.insert(v);
        }
        v = 1;
        for (auto it = tmp.begin(); it != tmp.end(); ++it) {
            if (*it != v) break;
            v += 1;
        }
        cout << v;
    }
};

int main(void)
{
    Solution s;
    s.missingNumber();
    return 0;
}
