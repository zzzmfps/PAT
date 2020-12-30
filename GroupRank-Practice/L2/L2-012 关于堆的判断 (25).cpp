#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int n, m;
    vector<int> heap;

public:
    Solution()
    {
        cin >> n >> m;
        heap.resize(n);
        for (int i = 0; i < n; ++i) { // one by one, order different from make_heap(begin, end)
            cin >> heap[i];
            push_heap(heap.begin(), heap.begin() + i + 1, greater<int>());
        }
    }

    void checkPropositions()
    {
        bool flag;
        for (int i = 0, val; i < m; ++i) {
            (cin >> val).get();
            if (cin.peek() == 'a') { // X and Y are siblings
                flag = checkSiblings(val);
            } else {
                cin.ignore(7);
                switch (cin.peek()) {
                    case 'r': flag = checkRoot(val); break;   // X is the root
                    case 'p': flag = checkParent(val); break; // X is the parent of Y
                    case 'i': flag = checkChild(val); break;  // X is a child of Y
                    default: break;
                }
            }
            cout << (flag ? 'T' : 'F') << '\n';
        }
    }

private:
    bool checkSiblings(int x)
    { // siblings indexed from 0: always odd -> even
        cin.ignore(3);
        int idx = distance(heap.begin(), find(heap.begin(), heap.end(), x));
        (cin >> x).ignore(13);
        return x == heap[idx + (idx & 1 ? 1 : -1)];
    }

    bool checkRoot(int x)
    { // simply the first one
        cin.ignore(4);
        return x == heap[0];
    }

    bool checkParent(int x)
    { // index(child_even) = (index(parent) + 1) * 2
        cin.ignore(9);
        int idx = (1 + distance(heap.begin(), find(heap.begin(), heap.end(), x))) << 1;
        cin >> x;
        return x == heap[idx] || x == heap[idx - 1];
    }

    bool checkChild(int x)
    { // index(parent) = (index(child) - 1) / 2
        cin.ignore(6);
        int idx = (distance(heap.begin(), find(heap.begin(), heap.end(), x)) - 1) >> 1;
        cin >> x;
        return x == heap[idx];
    }
};

int main(void)
{
    Solution s;
    s.checkPropositions();
    return 0;
}
