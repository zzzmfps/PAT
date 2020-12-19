#include <iostream>
using namespace std;

int main(void)
{
    int n, k, f, maxF, maxCount = 0;
    int record[1001] = {};
    cin >> n;
    while (n--) {
        cin >> k;
        while (k--) {
            cin >> f;
            record[f] += 1;
            if (record[f] > maxCount) {
                maxF = f, maxCount = record[f];
            } else if (record[f] == maxCount && f > maxF) {
                maxF = f;
            }
        }
    }
    cout << maxF << ' ' << maxCount;
    return 0;
}
