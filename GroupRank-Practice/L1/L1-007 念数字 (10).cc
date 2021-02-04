#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    const string p[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string num;
    cin >> num;
    for (int i = 0, size = num.size(); i < size; ++i) {
        if (i) cout << ' ';
        if (num[i] == '-') {
            cout << "fu";
        } else {
            cout << p[num[i] - 48];
        }
    }
    return 0;
}
