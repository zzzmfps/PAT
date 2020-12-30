#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int k, i = 0;
    cin >> k;
    while (true) {
        string str;
        cin >> str;
        if (str == "End") break;
        if (i == k) {
            cout << str << '\n';
            i = 0;
        } else {
            cout << (str == "Bu" ? "JianDao" : str == "JianDao" ? "ChuiZi" : "Bu") << '\n';
            ++i;
        }
    }
    return 0;
}
