#include <iomanip>
#include <iostream>
using namespace std;

int main(void)
{
    int a, b, _sum = 0;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        _sum += i;
        cout << setw(5) << i;
        if ((i - a + 1) % 5 == 0 || i == b) cout << '\n';
    }
    cout << "Sum = " << _sum;
    return 0;
}
