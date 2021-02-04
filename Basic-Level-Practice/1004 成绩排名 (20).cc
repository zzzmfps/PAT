#include <iostream>
#include <map>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    map<int, string> stu;
    int n;
    (cin >> n).get();
    while (n--) {
        string s;
        getline(cin, s);
        auto space = s.rfind(' ');
        stu[stoi(s.substr(space + 1))] = s.substr(0, space);
    }
    cout << stu.rbegin()->second << '\n' << stu.begin()->second;
    system("pause");
    return 0;
}
