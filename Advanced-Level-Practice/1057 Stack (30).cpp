#include <iostream>
#include <stack>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    const string POP = "Pop", PUSH = "Push";
    int n = 0, *nums, *blocks;

  public:
    Solution()
    {
        nums = new int[100001]{};
        blocks = new int[317]{};  // sqrt(100000).ceil()
    }

    ~Solution() { delete[] nums, blocks; }

    void process()
    {
        int k;
        cin >> k;
        stack<int> tmp;
        while (k--) {
            string order;
            cin >> order;
            if (order == PUSH) {
                push(tmp);
            } else if (order == POP) {
                pop(tmp);
            } else {
                peekMedian();
            }
        }
    }

  private:
    void push(stack<int> &tmp)
    {
        int x;
        cin >> x;
        tmp.push(x);
        ++n, ++nums[x], ++blocks[x / 316];  // sqrt(100000).floor()
    }

    void pop(stack<int> &tmp)
    {
        if (!n) {
            cout << "Invalid\n";
            return;
        }
        int x = tmp.top();
        cout << x << '\n';
        tmp.pop();
        --n, --nums[x], --blocks[x / 316];
    }

    void peekMedian()
    {
        if (!n) {
            cout << "Invalid\n";
            return;
        }
        int mid = (n + 1) / 2, b = -1, acc = 0;
        while (acc < mid) acc += blocks[++b];
        int i = 316 * (b + 1);
        while (true) {
            acc -= nums[--i];
            if (acc < mid) break;
        }
        cout << i << '\n';
    }
};

int main(void)
{
    Solution s;
    s.process();
    return 0;
}
