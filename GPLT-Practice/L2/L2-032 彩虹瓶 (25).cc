#include <iostream>
#include <stack>
using namespace std;

class Solution
{
private:
    int color, shelf, query;

public:
    Solution()
    {
        cin >> color >> shelf >> query;
    }

    void simulate()
    {
        for (int i = 0; i < query; ++i) {
            stack<int> st;
            int curColor = 1;
            for (int j = 0, c; j < color; ++j) {
                cin >> c;
                st.push(c);
                while (!st.empty() && st.top() == curColor) { // from shelf
                    st.pop();
                    curColor += 1;
                }
                if (st.size() > shelf) {
                    cin.ignore(0x3f3f3f3f, '\n'); // ignore the left boxes
                    break;
                }
            }
            cout << (st.empty() ? "YES" : "NO") << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.simulate();
    return 0;
}
