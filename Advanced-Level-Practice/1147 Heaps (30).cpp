#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void heaps()
    {
        int trees, nodes;
        cin >> trees >> nodes;
        vector<int> arr(nodes);
        while (trees--) {
            for (int i = 0; i < nodes; ++i) cin >> arr[i];
            if (is_heap(arr.begin(), arr.end(), less<int>())) {
                cout << "Max Heap\n";
            } else if (is_heap(arr.begin(), arr.end(), greater<int>())) {
                cout << "Min Heap\n";
            } else {
                cout << "Not Heap\n";
            }
            postOutput(arr, 0);
            cout << '\n';
        }
    }

private:
    void postOutput(const vector<int> &arr, int i)
    {
        if (i >= arr.size()) return;
        postOutput(arr, 2 * i + 1);
        postOutput(arr, 2 * i + 2);
        cout << arr[i] << (i ? " " : "");
    }
};

int main(void)
{
    Solution s;
    s.heaps();
    return 0;
}
