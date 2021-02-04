#include <iostream>
using namespace std;

void printHelper(int &cnt)
{
    cout << (cnt > 9 ? "27" : cnt > 3 ? "9" : string(cnt, '6'));
    cnt = 0;
}

int main(void)
{
    string str;
    getline(cin, str);
    int cnt = 0;
    for (int i = 0, size = str.size(); i < size; ++i) {
        if (str[i] == '6') cnt += 1;
        if (str[i] != '6' || i + 1 == size) printHelper(cnt);
        if (str[i] != '6') cout << str[i];
    }
    return 0;
}
