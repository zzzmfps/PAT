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
        int data, next = -1;
    };
    int beg, n, k, rounds;
    Node list[100001];

  public:
    Solution()
    {
        cin >> beg >> n >> k;
        int index, data, next;
        while (n--) {
            cin >> index >> data >> next;
            list[index].data = data;
            list[index].next = next;
        }
        for (int i = beg; i != -1; i = list[i].next) ++n;
        rounds = ++n / k;
        list[100000].next = beg;
    }

    void getReversedK()
    {
        int pre, cur, last = 100000, head;
        for (int i = 0; i < rounds; ++i) {
            head = last;
            pre = last = list[last].next;
            cur = list[pre].next;
            for (int j = 1; j < k; ++j) {
                list[last].next = list[cur].next;
                list[cur].next = pre;
                pre = cur;
                cur = list[last].next;
            }
            list[head].next = pre;
        }
        cout << setfill('0');
        beg = list[100000].next;
        while (true) {
            cout << setw(5) << beg << ' ' << list[beg].data << ' ';
            beg = list[beg].next;
            if (beg == -1) break;
            cout << setw(5) << beg << '\n';
        }
        cout << beg;
    }
};

int main(void)
{
    Solution s;
    s.getReversedK();
    return 0;
}
