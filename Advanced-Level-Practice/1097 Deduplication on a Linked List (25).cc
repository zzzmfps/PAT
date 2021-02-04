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
        int data, next;
    };
    Node list[100002];

  public:
    Solution()
    {
        int beg, n, cur, data, next;
        cin >> beg >> n;
        while (n--) {
            cin >> cur >> data >> next;
            list[cur].data = data;
            list[cur].next = next;
        }
        list[100000].next = beg;  // original
        list[100001].next = -1;   // removed
    }

    void unique()
    {
        bool counts[10001]{};
        int j = 100001;
        for (int pre = 100000, i = list[100000].next; i != -1; i = list[i].next) {
            int absv = abs(list[i].data);
            if (counts[absv]) {
                j = list[j].next = i;
                list[pre].next = list[i].next;
            } else {
                counts[absv] = true;
                pre = i;
            }
        }
        list[j].next = -1;
    }

    void printTwoLists()
    {
        cout << setfill('0');
        helper(list[100000].next);
        helper(list[100001].next);
    }

  private:
    void helper(int beg)
    {
        if (beg == -1) return;
        cout << setw(5) << beg << ' ' << list[beg].data << ' ';
        for (int i = list[beg].next; i != -1; i = list[i].next)
            cout << setw(5) << i << '\n' << setw(5) << i << ' ' << list[i].data << ' ';
        cout << "-1\n";
    }
};

int main(void)
{
    Solution s;
    s.unique();
    s.printTwoLists();
    return 0;
}
