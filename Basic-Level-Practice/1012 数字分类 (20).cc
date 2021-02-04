#include <iomanip>
#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    int all[5][2] = {}, num, count;
    cin>>count;
    while (count--) {
        cin >> num;
        switch (num % 5) {
            case 0:
                if (!(num & 1)) {
                    all[0][0] = 1;
                    all[0][1] += num;
                }
                break;
            case 1:
                all[1][0] += 1;
                all[1][1] += num * (all[1][0] & 1 ? 1 : -1);
                break;
            case 2: all[2][0] += 1; break;
            case 3:
                all[3][0] += 1;
                all[3][1] += num;
                break;
            case 4: all[4][1] = max(all[4][1], num); break;
        }
    }
    (all[0][0] ? cout << all[0][1] : cout << "N") << ' ';
    (all[1][0] ? cout << all[1][1] : cout << 'N') << ' ';
    (all[2][0] ? cout << all[2][0] : cout << 'N') << ' ';
    cout << setiosflags(ios_base::fixed) << setprecision(1);
    (all[3][0] ? cout << all[3][1] / double(all[3][0]) : cout << 'N') << ' ';
    (all[4][1] ? cout << all[4][1] : cout << 'N');
    system("pause");
    return 0;
}
