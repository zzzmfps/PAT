#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    void getPassword()
    {
        int n;
        cin >> n;
        string answer;
        while (n--) {
            for (int i = 0; i < 4; ++i) {
                cin >> answer;
                if (answer[2] == 'T') {
                    cout << int(answer[0] - 64);
                    cin.ignore(0x7FFFFFFF, '\n');
                    break;
                }
            }

        }
    }
};

int main(void)
{
    Solution s;
    s.getPassword();
    return 0;
}
