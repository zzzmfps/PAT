#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

auto getTime = [](int *t) {
    (cin >> t[0]).get();
    (cin >> t[1]).get();
    (cin >> t[2]).get();
};

auto timeCmp = [](int *tOld, int *tNew) {
    if (tOld[0] != tNew[0]) return tOld[0] < tNew[0];
    if (tOld[1] != tNew[1]) return tOld[1] < tNew[1];
    return tOld[2] < tNew[2];
};

auto timeSwap = [](int *tOld, int *tNew) {
    tOld[0] = tNew[0];
    tOld[1] = tNew[1];
    tOld[2] = tNew[2];
};

int main(void)
{
    string id1, id2, tmp;
    int t1[3]{23, 59, 59}, t2[3]{0, 0, 0}, t3[3];
    int n;
    cin >> n;
    while (n--) {
        cin >> tmp;
        getTime(t3);
        if (!timeCmp(t1, t3)) {
            id1 = tmp;
            timeSwap(t1, t3);
        }
        getTime(t3);
        if (timeCmp(t2, t3)) {
            id2 = tmp;
            timeSwap(t2, t3);
        }
    }
    cout << id1 << ' ' << id2;
    system("pause");
    return 0;
}
