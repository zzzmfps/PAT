#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    string str;
    getline(cin, str);
    int size = str.size();
    int n1 = (size + 2) / 3 - 1, n2 = size - n1 * 2, n2s = n2 - 2;
    for (int i = 0; i < n1; ++i) cout << str[i] << string(n2s, ' ') << str[size - 1 - i] << '\n';
    cout << str.substr(n1, n2);
    system("pause");
    return 0;
}
