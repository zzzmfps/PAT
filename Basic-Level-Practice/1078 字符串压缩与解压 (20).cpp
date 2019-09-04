#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    void translate()
    {
        char c;
        string origin;
        (cin >> c).get();
        getline(cin, origin);
        cout << (c == 'C' ? encode(origin) : decode(origin));
    }

private:
    string encode(const string &x)
    {
        string res = "";
        int count = 0;
        char last = x[0];
        for (auto c : x) {
            if (c == last) {
                count += 1;
            } else {
                if (count > 1) res += to_string(count);
                res += last;
                last = c, count = 1;
            }
        }
        if (count > 1) res += to_string(count);
        res += last;
        return res;
    }

    string decode(const string &x)
    {
        string res = "";
        int count = 0;
        for (auto c : x) {
            if (isalpha(c) || c == ' ') {
                res += string(max(1, count), c);
                count = 0;
            } else {
                count = count * 10 + c - 48;
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    s.translate();
    return 0;
}
