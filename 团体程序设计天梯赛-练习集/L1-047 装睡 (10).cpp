#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    while (n--) {
        string name;
        int v1, v2;
        cin >> name >> v1 >> v2;
        if (v1 < 15 || v1 > 20 || v2 < 50 || v2 > 70) cout << name << '\n';
    }
    return 0;
}
