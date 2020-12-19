#include <cmath>
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int i = 2, j = 2, max_i = n, max_j = n + 1;  // keep two pointers i and j
    int tmp = n, end = max_j - max_i + 5 + int(sqrt(n));  // set end for pruning
    while (j < end) {
        if (tmp % j == 0) {
            tmp /= j;  // if tmp is divisible by j
            j += 1;
        } else {
            if (j - i == max_j - max_i) {
                max_i = min(max_i, i), max_j = min(max_j, j);
            } else if (j - i > max_j - max_i) {
                max_i = i, max_j = j;
                end = max_j - max_i + 5 + int(pow(n, 1.0 / (max_j - max_i + 1)));
            }
            tmp *= i++;  // return i back
        }
    }
    cout << max_j - max_i << '\n' << max_i;
    for (int k = max_i + 1; k < max_j; ++k) cout << '*' << k;
    return 0;
}
