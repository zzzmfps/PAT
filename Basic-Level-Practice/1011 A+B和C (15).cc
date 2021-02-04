#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    int n, i = 0;
    long long a, b, c;
    cin >> n;
    while (i++ < n) {
        cin >> a >> b >> c;
        cout << "Case #" << i << ": " << boolalpha << (a + b > c);
        if (i < n) cout << '\n';
    }
    system("pause");
    return 0;
}
