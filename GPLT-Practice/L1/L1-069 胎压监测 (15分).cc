#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

static bool check(int x, int _min, int _max, int _diff) {
    return x < _min || _max - x > _diff;
}

int main(void) {
    int arr[4], minLimit, diffLimit;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> minLimit >> diffLimit;
    int maxLimit = max(max(arr[0], arr[1]), max(arr[2], arr[3]));

    int index = 0;
    for (int i = 0; i < 4; ++i) {
        if (check(arr[i], minLimit, maxLimit, diffLimit)) {
            index = (0 == index) ? 1 + i : -1;
        }
    }
    if (0 == index) {
        cout << "Normal";
    } else if (-1 == index) {
        cout << "Warning: please check all the tires!";
    } else {
        cout << "Warning: please check #" << index << "!";
    }

    return 0;
}
