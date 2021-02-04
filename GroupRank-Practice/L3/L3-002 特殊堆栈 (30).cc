#include <iostream>
#include <stack>
using namespace std;

class Solution
{
private:
    int median = 0, before = 0; // num of elems that before median
    int counts[100001] = {};
    stack<int> st;

public:
    void checkStack()
    {
        int n, val;
        (cin >> n).get();
        while (n--) {
            char c = cin.ignore(1).get();
            if (c == 'u') { // push
                cin.ignore(3) >> val;
                updateMedian(val, 1);
                st.push(val);
            } else if (st.empty()) {
                cout << "Invalid\n";
            } else if (c == 'o') { // pop
                cout << st.top() << '\n';
                updateMedian(st.top(), -1);
                st.pop();
            } else { // peek
                cout << median << '\n';
            }
            cin.ignore(0x3f3f3f3f, '\n');
        }
    }

private:
    void updateMedian(int _target, int delta)
    { /* Assuming all operations are valid.
         Median is updated before change the stack. */
        counts[_target] += delta;
        int required = (st.size() + delta + 1) >> 1;
        if (_target < median) before += delta;
        if (before >= required) { // real median is at the left
            while (counts[--median] == 0) continue;
            before -= counts[median];
        } else if (before + counts[median] < required) { // right
            before += counts[median];
            while (counts[++median] == 0) continue;
        }
    }
};

int main(void)
{
    Solution s;
    s.checkStack();
    return 0;
}
