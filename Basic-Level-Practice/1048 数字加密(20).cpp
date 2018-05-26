#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    // ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

static const char convert[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};

int main(void)
{
    string a, b;
    cin >> a >> b;
    int idxa = a.size(), idxb = b.size();
    int maxidx = max(idxa, idxb);
    // add leading zeroes to the shorter string
    if (maxidx > idxa)
        a = string(maxidx - idxa, '0') + a;
    else
        b = string(maxidx - idxb, '0') + b;
    for (int i = maxidx - 1; i > -1; i -= 2) b[i] = convert[(a[i] + b[i] - 96) % 13];
    for (int i = maxidx - 2; i > -1; i -= 2) {
        int tmp = b[i] - a[i];
        b[i] = (tmp < 0 ? tmp + 10 : tmp) + '0';
    }
    cout << b;
    system("pause");
    return 0;
}
