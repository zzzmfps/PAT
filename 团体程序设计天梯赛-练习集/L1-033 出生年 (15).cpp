#include <iomanip>
#include <iostream>
#include <unordered_set>
using namespace std;

int main(void)
{
    int year, n;
    cin >> year >> n;
    for (int i = year;; ++i) {
        unordered_set<int> tmp;
        tmp.insert(int(i / 1000));
        tmp.insert(int(i / 100) % 10);
        tmp.insert(int(i / 10) % 10);
        tmp.insert(i % 10);
        if (n == tmp.size()) {
            cout << i - year << ' ' << setw(4) << setfill('0') << i;
            break;
        }
    }
    return 0;
}
