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
    int n, *original, *partial;

  public:
    Solution()
    {
        cin >> n;
        original = new int[n + 1];
        for (int i = 1; i <= n; ++i) cin >> original[i];
        partial = new int[n + 1];
        for (int i = 1; i <= n; ++i) cin >> partial[i];
    }

    void checkAndOutput()
    {
        int right = is_sorted_until(partial + 1, partial + n + 1) - partial, k = n;
        while (partial[k] == original[k]) --k;
        if (right >= k + 1) {
            cout << "Insertion Sort\n";
            insertionSort(1, right, n + 1);
        } else {
            cout << "Heap Sort\n";
            heapSort(1, find_if(partial + 2, partial + n + 1, [this](int x) { return x > partial[1]; }) - partial - 1);
        }
        cout << partial[1];
        for (int i = 2; i <= n; ++i) cout << ' ' << partial[i];
    }

  private:
    void insertionSort(int beg, int next, int end) { sort(partial + 1, partial + next + 1); }

    void heapSort(int beg, int end)
    {
        swap(partial[1], partial[end--]);
        downAdjust(1, end);
    }

    void downAdjust(int beg, int end)
    {
        int i = beg, j = i * 2;
        while (j <= end) {
            if (j + 1 <= end && partial[j + 1] > partial[j]) ++j;
            if (partial[i] > partial[j]) break;
            swap(partial[i], partial[j]);
            i = j, j *= 2;
        }
    }
};

int main(void)
{
    Solution s;
    s.checkAndOutput();
    return 0;
}
