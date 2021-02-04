#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

static const string days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(void)
{
    /*
    ** Note1. directly print the result if there's no need of modifying or storing it
    ** Note2. do not try to compute the sum of literal constants (char/const char *)
    **        '1' + '2' - only one that valid, equals to int('1') + int('2'),
    **        "1" + "2" - invalid,
    **        '1' + "2" - yields a pointer const char *p, *p = 0 '\000',
    **        "1" + '2' - same as '1' + "2",
    ** a + b - always valid even they're const, yields an int if both are char-type, otherwise a string
    */
    
    string times[4];

    // input
    int i = 0;
    for (; i < 4; ++i) getline(cin, times[i]);

    // str1,2 first pair of letters, A-G
    int length = min(times[0].size(), times[1].size());
    for (i = 0; i < length; ++i)
        if (times[0][i] == times[1][i] && times[0][i] >= 'A' && times[0][i] <= 'G') break;
    cout << days[times[0][i] - 'A'] << ' ';

    // str1,2 second pair of letters, hour, 0-9,A-N
    for (i += 1; i < length; ++i)
        if (times[0][i] == times[1][i] &&
            (times[0][i] >= '0' && times[0][i] <= '9' || times[0][i] >= 'A' && times[0][i] <= 'N'))
            break;
    cout << setw(2) << setfill('0') << (times[0][i] <= '9' ? times[0][i] - 48 : times[0][i] - 55);

    // str3,4 first pair of letters, minute, A-Z,a-z
    length = min(times[2].size(), times[3].size());
    for (i = 0; i < length; ++i)
        if (times[2][i] == times[3][i] &&
            (times[2][i] >= 'A' && times[2][i] <= 'Z' || times[2][i] >= 'a' && times[2][i] <= 'z'))
            break;
    cout << ':' << setw(2) << setfill('0') << i;
    system("pause");
    return 0;
}
