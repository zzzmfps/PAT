#include <iostream>
using namespace std;

static const int stdhw[2][2] = {{129, 25}, {130, 27}};

int main(void)
{
    int n;
    cin >> n;
    while (n--) {
        int gender, height, weight;
        cin >> gender >> height >> weight;
        if (height < stdhw[gender][0]) {
            cout << "duo chi yu! ";
        } else if (height > stdhw[gender][0]) {
            cout << "ni li hai! ";
        } else {
            cout << "wan mei! ";
        }
        if (weight < stdhw[gender][1]) {
            cout << "duo chi rou!\n";
        } else if (weight > stdhw[gender][1]) {
            cout << "shao chi rou!\n";
        } else {
            cout << "wan mei!\n";
        }
    }
    return 0;
}
