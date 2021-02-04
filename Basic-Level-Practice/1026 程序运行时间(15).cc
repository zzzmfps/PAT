#include <iomanip>
#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    int c1, c2;
    cin >> c1 >> c2;
    int seconds = int((c2 - c1) / 100.0 + 0.5);
    int sec = seconds % 60;
    seconds /= 60;
    int min = seconds % 60;
    int hrs = seconds / 60;
    cout << setw(2) << setfill('0') << hrs << ':';
    cout << setw(2) << setfill('0') << min << ':';
    cout << setw(2) << setfill('0') << sec;
    system("pause");
    return 0;
}
