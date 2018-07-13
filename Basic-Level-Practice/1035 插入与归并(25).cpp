#include <algorithm>
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
    int n, *seq1, *seq2;

  public:
    Solution()
    {
        cin >> n;
        seq1 = new int[n];
        for (int i = 0; i < n; ++i) cin >> seq1[i];
        seq2 = new int[n];
        for (int i = 0; i < n; ++i) cin >> seq2[i];
    }

    void getNextSeq()
    {
        int range = 2;
        while (range < n) {
            nextMergeSortSeq(seq1, range);
            range <<= 1;
            if (isTwoSeqEqual()) {
                cout << "Merge Sort\n";
                nextMergeSortSeq(seq1, range);
                printSeq(seq1);
                return;
            }
        }
        cout << "Insertion Sort\n";
        nextInsertSortSeq(seq2, 1 + (is_sorted_until(seq2, seq2 + n) - seq2));
        printSeq(seq2);
    }

  private:
    void nextInsertSortSeq(int *seq, int len) { sort(seq, seq + len); }

    void nextMergeSortSeq(int *seq, int len)
    {
        int left = 0, right = len;
        while (right < n) {
            sort(seq + left, seq + right);
            left = right, right += len;
        }
        sort(seq + left, seq + n);
    }

    bool isTwoSeqEqual()
    {
        bool flag = true;
        for (int i = 0; i < n; ++i)
            if (seq1[i] != seq2[i]) {
                flag = false;
                break;
            }
        return flag;
    }

    void printSeq(int *seq)
    {
        cout << seq[0];
        for (int i = 1; i < n; ++i) cout << ' ' << seq[i];
    }
};

int main(void)
{
    Solution s;
    s.getNextSeq();
    return 0;
}
