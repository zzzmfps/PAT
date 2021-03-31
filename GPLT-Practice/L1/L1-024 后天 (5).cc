#include <iostream>
using namespace std;

int main(void)
{
    int d;
    cin >> d;
    cout << (d < 6 ? d + 2 : (d + 2) % 7);
    return 0;
}
