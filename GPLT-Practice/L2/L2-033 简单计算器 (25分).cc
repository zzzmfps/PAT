#include <iostream>
#include <stack>
using namespace std;

template <typename T> stack<T> getStack(int size)
{
    stack<T> st;
    for (int i = 0; i < size; ++i) {
        st.emplace(0);
        cin >> st.top();
    }
    return st;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    stack<int> nums = getStack<int>(n);
    stack<char> ops = getStack<char>(n - 1);
    for (int i = n - 1; i > 0; --i) {
        int y = nums.top();
        char op = ops.top();
        nums.pop(), ops.pop();
        switch (op) {
            case '+': nums.top() += y; break;
            case '-': nums.top() -= y; break;
            case '*': nums.top() *= y; break;
            case '/':
                if (0 == y) {
                    cout << "ERROR: " << nums.top() << "/0";
                    return 0;
                }
                nums.top() /= y;
        }
    }
    cout << nums.top();
    return 0;
}
