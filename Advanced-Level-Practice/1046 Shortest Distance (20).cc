#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    int nums, pairs, beg, end, sum = 0;
    cin >> nums;
    int *exits = new int[nums + 1](), *dists = new int[nums + 1]();
    for (int i = 1; i <= nums; ++i) {
        cin >> exits[i];
        sum += exits[i];
        dists[i] = sum;
    }
    cin >> pairs;
    while (pairs--) {
        cin >> beg >> end;
        if (--beg > --end) swap(beg, end);
        int dist1 = dists[end] - dists[beg];
        int dist2 = sum - dist1;
        cout << (dist1 < dist2 ? dist1 : dist2);
        if (pairs > 0) cout << '\n';
    }
    system("pause");
    return 0;
}
