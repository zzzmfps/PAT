#include <iostream>
using namespace std;

int main(void)
{
    int p[2][2] = {};
    cin >> p[0][0] >> p[1][0];
    for (int i = 0, tmp; i < 3; ++i) {
        cin >> tmp;
        p[tmp][1] += 1;
    }
    int winner = (p[0][0] > p[1][0] && p[0][1] || p[0][1] == 3 ? 0 : 1);
    cout << "The winner is " << (winner == 0 ? 'a' : 'b') << ": " << p[winner][0] << " + " << p[winner][1];
    return 0;
}
