#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string time;
    cin >> time;
    if (time < "12:01") {
        cout << "Only " << time << ".  Too early to Dang.";
    } else {
        int hr = 10 * (time[0] == '1' ? 0 : 1) + time[1] - 50; // hr - 12
        if (time[3] != '0' || time[4] != '0') hr += 1;
        while (hr--) cout << "Dang";
    }
    return 0;
}
