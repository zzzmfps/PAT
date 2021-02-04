#include <iostream>
using namespace std;

int main(void)
{
    int n;
    char fill;
    string str;
    (cin >> n >> fill).get();
    getline(cin, str);
    if (n <= str.size()) {
        cout << str.substr(str.size() - n);
    } else {
        cout << string(n - str.size(), fill) << str;
    }
    return 0;
}
