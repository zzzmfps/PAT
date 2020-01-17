#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    bool avg[100000] = {};  // better than unordered_set, because id is restricted to [0, 99999]
    vector<int> handsome;
    int n, m;
    cin >> n;
    while (n--) {
        cin >> m;
        if (m == 1) {
            cin.ignore(10, '\n');
            continue;
        }
        int id;
        while (m--) {
            cin >> id;
            avg[id] = true;
        }
    }
    cin >> n;
    while (n--) {
        cin >> m;
        if (!avg[m]) handsome.push_back(m), avg[m] = true;
    }
    if (handsome.empty()) {
        cout << "No one is handsome";
    } else {
        cout << setw(5) << setfill('0') << handsome[0];  // print '00121' not '121' and likewise
        for (int i = 1, size = handsome.size(); i < size; ++i) cout << ' ' << setw(5) << setfill('0') << handsome[i];
    }
    return 0;
}
