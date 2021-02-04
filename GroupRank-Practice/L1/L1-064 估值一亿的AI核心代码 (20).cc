#include <iostream>
#include <regex>
#include <string>
using namespace std;

const regex expr[6] = {regex("(^ +| +$)"),             // heading or trailing whitespaces
                       regex(" +([^a-zA-Z0-9])"),      // whitespaces continuous or before marks
                       regex("\\b(can|could) you\\b"), // can/could you to I can/could
                       regex("\\b(I|me)\\b"),          // I/me to you
                       regex("%%%%"),                  // HOW to replace at the SAME time, without taking an extra step?
                       regex("\\?")};                  // ? to !
const string rep[6] = {"", "$1", "%%%% $1", "you", "I", "!"};

int main(void)
{
    int n;
    (cin >> n).get();
    while (n--) {
        string str;
        getline(cin, str);
        cout << str << '\n';
        for (auto &c : str) c = (c == 'I' ? c : tolower(c)); // to lowercase except 'I'
        for (int i = 0; i < 6; ++i) str = regex_replace(str, expr[i], rep[i]);
        cout << "AI: " << str << '\n';
    }
    return 0;
}
