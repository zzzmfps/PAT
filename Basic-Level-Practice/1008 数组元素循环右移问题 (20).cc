#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    int n, m;
    cin >> n >> m;
    m %= n;
    int *arr = new int[n];
    for (int i = m; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < m; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) cout << ' ';
    }
    system("pause");
    return 0;
}
