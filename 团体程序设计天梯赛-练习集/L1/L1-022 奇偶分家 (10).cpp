#include <iostream>
using namespace std;

int main(void)
{
    int n, num, odds = 0, evens = 0;
    cin >> n;
    while (n--) {
        cin >> num;
        num & 1 ? ++odds : ++evens;
    }
    cout << odds << ' ' << evens;
    return 0;
}
