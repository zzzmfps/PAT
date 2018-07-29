#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    struct Node {
        int addr, data;
    };
    Node *list;  // addr --> cur.addr
    int n, beg;

  public:
    Solution()
    {
        cin >> n >> beg;
        Node tmp[100000];  // addr --> next.addr
        for (int i = 0, cur, data, next; i < n; ++i) {
            cin >> cur >> data >> next;
            tmp[cur].data = data;
            tmp[cur].addr = next;
        }

        n = 0;
        for (int i = beg; i != -1; i = tmp[i].addr) ++n;

        list = new Node[n];
        for (int i = beg, j = 0; i != -1; i = tmp[i].addr, ++j) {
            list[j].addr = i;
            list[j].data = tmp[i].data;
        }
    }

    void sortLinkedList()
    {
        sort(list, list + n, [](const Node &x, const Node &y) { return x.data < y.data; });
        cout << setfill('0') << n;
        for (int i = 0; i < n; ++i)
            cout << ' ' << setw(5) << list[i].addr << '\n' << setw(5) << list[i].addr << ' ' << list[i].data;
        cout << " -1";
    }
};

int main(void)
{
    Solution s;
    s.sortLinkedList();
    return 0;
}
