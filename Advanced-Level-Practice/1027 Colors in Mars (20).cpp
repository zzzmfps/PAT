#include <iomanip>
#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

static const char mars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
static const int base = 13;

int main(void)
{
    string color = "";
    int tmp;
    cout << '#';
    for (int i = 0; i < 3; ++i) {
        cin >> tmp;
        while (tmp) {
            color = mars[tmp % base] + color;
            tmp /= base;
        }
        cout << setfill('0') << setw(2) << color;
        color.clear();
    }
    system("pause");
    return 0;
}
