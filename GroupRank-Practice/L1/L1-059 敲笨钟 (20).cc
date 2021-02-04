#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    (cin >> n).get();
    while (n--) {
        string str;
        getline(cin, str);
        int it1 = str.find(','), it2 = str.find('.');
        // max(0, it1 - 3) is needed, or testcase 4 will report Runtime Error
        // length of the first half sentence less than 3 ??
        if (str.substr(max(0, it1 - 3), 3) == "ong" && str.substr(it2 - 3, 3) == "ong") {
            int it3 = str.size() - 1;
            for (int i = 0; i < 3; ++i) it3 = str.rfind(' ', it3 - 1);
            cout << str.substr(0, it3) << " qiao ben zhong.\n";
        } else {
            cout << "Skipped\n";
        }
    }
    return 0;
}
