#include <iostream>
#include <regex>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    string sciNum[5];
    getline(cin, sciNum[0]);
    regex re("([+-])([1-9])\\.([0-9]+)E([+-][0-9]+)");
    smatch sm;
    regex_match(sciNum[0], sm, re);
    for (int i = 1; i < 5; ++i) sciNum[i] = sm[i].str();

    int expo = stoi(sciNum[4]);
    if (expo >= 0) {
        int length = sciNum[3].size();
        if (expo >= length) {
            sciNum[3] += string(expo - length, '0');
        } else {
            sciNum[3].insert(expo, ".");
        }
    } else {
        sciNum[2] = "0." + string(-expo - 1, '0') + sciNum[2];
    }

    if (sciNum[1] == "-") cout << '-';
    cout << sciNum[2] << sciNum[3];

    system("pause");
    return 0;
}
