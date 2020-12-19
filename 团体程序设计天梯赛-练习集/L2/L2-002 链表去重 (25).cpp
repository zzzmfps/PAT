#include <iomanip>
#include <iostream>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution
{
private:
    static const int maxNode = 100000;
    int head, num, deleted = -1;
    pair<int, int> link[maxNode]; // next, val

public:
    Solution()
    {
        cin >> head >> num;
        for (int i = 0, n1, v, n2; i < num; ++i) {
            cin >> n1 >> v >> n2;
            link[n1] = make_pair(n2, v);
        }
    }

    void unique()
    {
        unordered_set<int> us({abs(link[head].second)});
        int cur = head, dcur;
        while (link[cur].first != -1) {
            int _next = link[cur].first;
            if (us.find(abs(link[_next].second)) == us.end()) { // new value
                us.insert(abs(link[_next].second));
                cur = _next;
            } else { // not unique
                if (deleted == -1) deleted = _next, dcur = _next; // initial link of deleted values
                link[cur].first = link[_next].first;
                link[_next].first = -1;
                if (dcur != _next) link[dcur].first = _next, dcur = _next;
                if (link[cur].first == -1) break;
            }
        }
        printLink(head);
        printLink(deleted);
    }

private:
    void printLink(int head)
    {
        cout << setfill('0');
        while (head != -1) { // ignore empty link
            cout << setw(5) << head << ' ' << link[head].second << ' ';
            head = link[head].first;
            if (head != -1) cout << setw(5);
            cout << head << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.unique();
    return 0;
}
