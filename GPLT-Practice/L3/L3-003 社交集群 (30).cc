#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    bool exist[1001] = {}; // is the n-th interest occurred in data
    int interests[1001];   // ufs for interests
    int counts[1001] = {}; // counter for interests

public:
    Solution()
    {
        for (int i = 1; i < 1001; ++i) interests[i] = i;
        int n, k, h1, h2;
        cin >> n;
        while (n--) {
            (cin >> k).get();
            cin >> h1;
            counts[h1] += 1;
            exist[h1] = true;
            while (--k) {
                cin >> h2;
                join(h1, h2), exist[h2] = true;
            }
        }
    }

    void printClusterNum()
    {
        unordered_map<int, int> rec;
        for (int i = 1; i < 1001; ++i)
            if (exist[i]) rec[findRoot(i)] += counts[i];
        int size = rec.size();

        int *nums = new int[size], i = 0;
        for (auto &p : rec) nums[i++] = p.second;
        sort(nums, nums + size, greater<int>());

        cout << size;
        for (int j = 0; j < size; ++j) cout << (j ? ' ' : '\n') << nums[j];
    }

private:
    int findRoot(int x)
    {
        if (x == interests[x]) return x;
        return interests[x] = findRoot(interests[x]);
    }

    int join(int x, int y)
    {
        x = findRoot(x), y = findRoot(y);
        interests[y] = x;
    }
};

int main(void)
{
    Solution s;
    s.printClusterNum();
    return 0;
}
