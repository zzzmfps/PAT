#include <iostream>
using namespace std;

int main(void)
{
    int num, count = 0;
    cin >> num;
    while (num > 1) {
        num = (num & 1 ? 3 * num + 1 : num) / 2;
        ++count;
    }
    cout << count;
    return 0;
}
