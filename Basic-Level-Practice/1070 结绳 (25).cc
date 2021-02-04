#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestString()
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];
        if (n == 2) return int((arr[0] + arr[1]) / 2);
        sort(arr, arr + n, greater<int>());
        double res = 0.0;
        for (int i = 0; i < n; ++i) res += arr[i] / pow(2, i + 1);
        delete[] arr;
        return int(res);
    }
};

int main(void)
{
    Solution s;
    cout << s.longestString();
    return 0;
}
