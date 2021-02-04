#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    unordered_map<int, pair<long long, int>> stu;
    int count, seat1, seat2, seat3;
    cin >> count;
    long long id;
    while (count--) {
        cin >> id >> seat1 >> seat2;
        stu.insert(make_pair(seat1, make_pair(id, seat2)));
    }
    cin >> count;
    while (count--) {
        cin >> seat3;
        cout << stu[seat3].first << ' ' << stu[seat3].second;
        if (count) cout << '\n';
    }
    system("pause");
    return 0;
}
