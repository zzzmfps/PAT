#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int length;
    cin >> length;
    vector<double> arr(length);
    for (int i = 0; i < length; ++i) cin >> arr[i];

    double res = 0.0;
    for (auto &&num : arr) res += 1.0 / num;
    cout << fixed << setprecision(2) << length / res;
    return 0;
}
