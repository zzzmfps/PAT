#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    void checkPassword()
    {
        int n;
        (cin >> n).get();
        string pw;
        while (n--) {
            getline(cin, pw);
            cout << "Your password ";
            switch (helper(pw)) {
                case 0: cout << "is wan mei"; break;
                case 1: cout << "is tai duan le"; break;
                case 2: cout << "is tai luan le"; break;
                case 3: cout << "needs shu zi"; break;
                case 4: cout << "needs zi mu"; break;
            }
            cout << ".\n";
        }
    }

private:
    int helper(const string &pw)
    {
        if (pw.size() < 6) return 1;    // too short
        bool allalpha = true, allnum = true;
        for (auto c : pw) {
            if (isdigit(c)) {
                allalpha = false;
            } else if (isalpha(c)) {
                allnum = false;
            } else if (!isalnum(c) && c != '.') {
                return 2;   // illegal char
            }
        }
        if (allalpha) return 3;
        if (allnum) return 4;
        return 0;   // legal
    }
};

int main(void)
{
    Solution s;
    s.checkPassword();
    return 0;
}
