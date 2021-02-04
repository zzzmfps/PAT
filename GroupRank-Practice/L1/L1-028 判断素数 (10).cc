#include <cmath>
#include <iostream>
using namespace std;

bool isPrime(int x)
{
    if (x == 1) return false;
    for (int i = 2, end = 1 + int(sqrt(x)); i < end; ++i)
        if (x % i == 0) return false;
    return true;
}

int main(void)
{
    int n, v;
    cin >> n;
    while (n--) {
        cin >> v;
        cout << (isPrime(v) ? "Yes" : "No") << '\n';
    }
    return 0;
}
