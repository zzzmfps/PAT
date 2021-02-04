#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    void heapPaths()
    {
        int n;
        cin >> n;
        vector<int> heap(n), tmp;
        for (int i = 0; i < n; ++i) cin >> heap[i];
        traverse(heap, tmp, 0);
        string type = (is_heap(heap.begin(), heap.end(), greater<int>()) ? "Min Heap" :
                       is_heap(heap.begin(), heap.end(), less<int>()) ? "Max Heap" : "Not Heap");
        cout << type << '\n';
    }

private:
    void traverse(const vector<int> &heap, vector<int> &tmp, int i)
    {
        int sh = heap.size();
        tmp.push_back(heap[i]);
        if (2 * i + 2 < heap.size()) {
            traverse(heap, tmp, 2 * i + 2);
            traverse(heap, tmp, 2 * i + 1);
        } else if (2 * i + 1 < heap.size()) {
            traverse(heap, tmp, 2 * i + 1);
        } else {
            for (int j = 0, st = tmp.size(); j < st; ++j)
                cout << (j ? " " : "") << tmp[j];
            cout << '\n';
        }
        tmp.pop_back();
    }
};

int main(void)
{
    Solution s;
    s.heapPaths();
    return 0;
}
