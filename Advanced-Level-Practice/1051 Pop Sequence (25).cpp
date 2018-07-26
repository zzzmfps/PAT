#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    int capacity, length, seqs;
    set<int> initial;

  public:
    Solution()
    {
        cin >> capacity >> length >> seqs;
        for (int i = 1; i <= length; ++i) initial.insert(i);
    }

    void checkSequences()
    {
        while (seqs--) {
            set<int> tmp(initial);
            int last, cur, i = 1;
            cin >> last;
            if (!checkLengthLimit(last, i))
                for (i = 2; i <= length; ++i) {
                    tmp.erase(last);
                    cin >> cur;
                    if (cur > last && checkLengthLimit(cur, i)) break;
                    if (cur < last && checkNumbersLeft(tmp, last, cur)) break;
                    last = cur;
                }
            cout << (i > length ? "YES" : "NO") << '\n';
            cin.ignore(0x7FFFFFFF, '\n');
        }
    }

  private:
    bool checkLengthLimit(int x, int i) const { return x - i >= capacity; }

    bool checkNumbersLeft(const set<int> &s, int r, int l) const { return s.upper_bound(l) != s.upper_bound(r); }
};

int main(void)
{
    Solution s;
    s.checkSequences();
    return 0;
}
