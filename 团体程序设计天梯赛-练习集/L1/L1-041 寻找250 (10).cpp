#include <iostream>
using namespace std;

int main(void)
{
    int i = 0, num;
    while (++i) {
        cin >> num;
        if (num != 250) continue;
        cout << i;
        break;
    }
    return 0;
}
