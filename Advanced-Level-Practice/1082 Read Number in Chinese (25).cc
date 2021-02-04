#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

static const string decimal[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
static const string chinese[] = { " Qian", "", " Shi", " Bai" };

int main(void)
{
    string num;
    bool isFirst = true;
    if (cin.peek() == '-') {
        cin.get();
        cout << "Fu";
        isFirst = false;
    } else if (cin.peek() == '0') {
        cout << decimal[0];
        return 0;
    }
    getline(cin, num);
    bool inZeroes = false;
    bool is_wan_exist = false;	// fix 8,0000,0008
    for (int i = 0, length = num.size(); i < length; ++i) {
        int diff = length - i;
        if (num[i] == '0') {
            if (!inZeroes) inZeroes = true;
        } else {
            if (inZeroes) {
                cout << ' ' << decimal[0];
                inZeroes = false;
            }
            if (isFirst) {
                isFirst = false;
            } else {
                cout << ' ';
            }
            if (num[i] != '0' && diff > 4 && diff < 9) is_wan_exist = true;
            cout << decimal[num[i] - '0'] << chinese[diff % 4];
        }
        if (diff == 9) {
            cout << " Yi";
        } else if (diff == 5 && is_wan_exist) {
            cout << " Wan";
        }
    }
    cin.get();
    return 0;
}
