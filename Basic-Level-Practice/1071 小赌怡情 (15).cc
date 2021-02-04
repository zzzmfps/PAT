#include <iostream>
using namespace std;

class Solution
{
public:
    void gamble()
    {
        int tokens, k;
        cin >> tokens >> k;
        int n1, b, t, n2;
        while (k--) {
            cin >> n1 >> b >> t >> n2;
            if (t > tokens) {
                cout << "Not enough tokens.  Total = " << tokens << ".\n";
            } else if (b == (n2 > n1)) {
                tokens += t;
                cout << "Win " << t << "!  Total = " << tokens << ".\n";

            } else {
                tokens -= t;
                cout << "Lose " << t << ".  Total = " << tokens << ".\n";
                if (tokens == 0) {
                    cout << "Game Over.";
                    break;
                }
            }
        }
    }
};

int main(void)
{
    Solution s;
    s.gamble();
    return 0;
}
