#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    int n, _sum = 0;
    cin >> n;
    map<int, string> records;
    for (int i = 0, guess; i < n; ++i) {
        string name;
        cin >> name >> guess;
        records[guess] = name;
        _sum += guess;
    }
    int avg2 = int(_sum * 0.5 / n);
    auto it2 = records.upper_bound(avg2);
    cout << avg2 << ' ';
    if (it2 == records.begin()) {
        cout << it2->second;
    } else {
        auto it1 = prev(it2);
        if (it2 == records.end()) {
            cout << it1->second;
        } else {
            cout << (avg2 - it1->first < it2->first - avg2 ? it1 : it2)->second;
        }
    }
    return 0;
}
