#include <iostream>
#include <numeric>
using namespace std;

int main(void)
{
    int s[11] = {1, 1}, n;
    cin >> n;
    for (int i = 2; i <= n; ++i) s[i] = s[i - 1] * i;
    cout << accumulate(s + 1, s + n + 1, 0);
    return 0;
}
