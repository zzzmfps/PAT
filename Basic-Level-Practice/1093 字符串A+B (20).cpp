#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    void uniqueUnion()
    {
        bool *tmp = new bool[127] {};
        for (int i = 0; i < 2; ++i) {
            string a;
            getline(cin, a);
            for (auto c : a) {
                if (!tmp[c]) {
                    tmp[c] = true;
                    cout << c;
                }
            }
        }
        delete[] tmp;
    }
};

int main(void)
{
    Solution s;
    s.uniqueUnion();
    return 0;
}
