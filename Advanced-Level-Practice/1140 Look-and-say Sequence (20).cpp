#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    void sequence()
    {
        int d, k;
        cin >> d >> k;
        string res(1, char(d + 48));
        for (int i = 1; i < k; ++i) {
            res += '.';
            string tmp = "";
            char last = res[0];
            int count = 0;
            for (auto c : res) {
                if (c == last) {
                    count += 1;
                } else {
                    tmp += last + to_string(count);
                    last = c, count = 1;
                }
            }
            res.swap(tmp);
        }
        cout << res;
    }
};

int main(void)
{
    Solution s;
    s.sequence();
    return 0;
}
