#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    void checkPassword()
    {
        string correct;
        int n;
        (cin >> correct >> n).get();
        while (n--) {
            string tmp;
            getline(cin, tmp);
            if (tmp == "#") return;
            if (tmp == correct) {
                cout << "Welcome in\n";
                return;
            } else {
                cout << "Wrong password: " << tmp << '\n';
            }
        }
        cout << "Account locked\n";
    }
};


int main(void)
{
    Solution s;
    s.checkPassword();
    return 0;
}
