#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    while (n--) {
        string lottery;
        cin >> lottery;
        int lval = lottery[0] + lottery[1] + lottery[2] - 144;
        int rval = lottery[3] + lottery[4] + lottery[5] - 144;
        cout << (lval == rval ? "You are lucky!" : "Wish you good luck.") << '\n';
    }
    return 0;
}
