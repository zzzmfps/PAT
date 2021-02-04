#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    vector<string> names(2);
    for (int i = 1; i < 15; ++i) {
        if (cin.peek() == '.') break;
        if (i != 2 && i != 14) {
            cin.ignore(12, '\n');
        } else { // i: 2 to 0, and 14 to 1
            getline(cin, names[int(i / 14)]);
        }
    }
    cin.ignore(0x7FFFFFFF, '.');

    if (names[0] == "") {
        cout << "Momo... No one is for you ...";
    } else if (names[1] == "") {
        cout << names[0] << " is the only one for you...";
    } else {
        cout << names[0] << " and " << names[1] << " are inviting you to dinner...";
    }

    return 0;
}
