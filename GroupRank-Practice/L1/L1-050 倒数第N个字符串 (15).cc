#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int l, n;
    cin >> l >> n;
    n -= 1; // index from 1, not 0
    string str(l, 'z');
    vector<int> tmp;
    while (n) {
        tmp.push_back(n % 26);
        n /= 26;
    }
    for (int i = 0, size = tmp.size(); i < size; ++i) str[l - 1 - i] -= tmp[i];
    cout << str;
    return 0;
}
