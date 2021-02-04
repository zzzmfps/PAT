#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int *m = new int[n];
    for (int i = 0; i < n; ++i) cin >> m[i], m[i] *= 10;
    // add seats
    vector<vector<int>> seats(n);
    int index = 1;
    while (true) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (m[i]) {
                m[i] -= 1;
                seats[i].push_back(index++);
                cnt += (m[i] > 0);
            }
        }
        if (cnt < 2) {
            if (cnt == 1) { // if there's one school left
                int sch = find_if(m, m + n, [](int x) { return x > 0; }) - m;
                // players from the same school are not allowed to be close to each other
                // but is accepted if from different schools
                index = max(index, seats[sch].back() + 2);
                for (int i = m[sch]; i > 0; --i) {
                    seats[sch].push_back(index);
                    index += 2;
                }
            }
            break;
        }
    }
    // print seats
    for (int i = 0; i < n; ++i) {
        cout << '#' << i + 1 << '\n';
        for (int j = 0, size = seats[i].size(); j < size; ++j) cout << seats[i][j] << ((j + 1) % 10 ? ' ' : '\n');
    }
    delete[] m;
    return 0;
}
