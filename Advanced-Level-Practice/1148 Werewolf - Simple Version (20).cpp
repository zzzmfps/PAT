#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void findWolves()
    {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; ++i) cin >> arr[i];
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                vector<int> lies;
                vector<bool> tmp(n + 1, false);
                tmp[i] = tmp[j] = true;
                for (int k = 1; k <= n; ++k) {
                    if (arr[k] > 0 && !tmp[arr[k]]) continue;
                    if (arr[k] < 0 && tmp[-arr[k]]) continue;
                    lies.push_back(k);
                }
                if (lies.size() != 2 || tmp[lies[0]] == tmp[lies[1]]) continue;
                cout << i << ' ' << j;
                return;
            }
        }
        cout << "No Solution";
    }
};

int main(void)
{
    Solution s;
    s.findWolves();
    return 0;
}
