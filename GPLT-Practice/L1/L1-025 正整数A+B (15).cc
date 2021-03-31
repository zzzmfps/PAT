#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
    string str1, str2, str3;
    getline(cin, str2);
    int delim = str2.find(' ');
    str1 = str2.substr(0, delim);
    str2 = str2.substr(delim + 1);
    bool flag1 = all_of(str1.begin(), str1.end(), [](char c) { return isdigit(c); });
    bool flag2 = all_of(str2.begin(), str2.end(), [](char c) { return isdigit(c); });
    if (!flag1 || str1 == "0" || stoi(str1) > 1000) str1 = "?";
    if (!flag2 || str2 == "0" || stoi(str2) > 1000) str2 = "?";
    str3 = (str1 == "?" || str2 == "?" ? "?" : to_string(stoi(str1) + stoi(str2)));
    cout << str1 << " + " << str2 << " = " << str3;
    return 0;
}
