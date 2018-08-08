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
    int n, *clusters, *hobbies, *nums;

  public:
    Solution()
    {
        cin >> n;
        clusters = new int[n + 1];
        for (int i = 1; i <= n; ++i) clusters[i] = i;

        hobbies = new int[1001]{};
        for (int i = 1, k, h; i <= n; ++i) {
            (cin >> k).ignore(1);
            while (k--) {
                cin >> h;
                if (hobbies[h]) {
                    clusterUnion(i, hobbies[h]);
                } else {
                    hobbies[h] = i;
                }
            }
        }

        nums = new int[n + 1]{};
        for (int i = 1; i <= n; ++i) ++nums[getRoot(i)];
    }

    void printClusters()
    {
        sort(nums + 1, nums + n + 1, greater<int>());
        int count = 0, end = n + 1;
        for (int i = 1; i <= n; ++i)
            if (nums[i]) {
                ++count;
            } else {
                end = i;
                break;
            }
        cout << count << '\n' << nums[1];
        for (int i = 2; i < end; ++i) cout << ' ' << nums[i];
    }

  private:
    int getRoot(int x)
    {
        int tmp = x;
        while (x != clusters[x]) x = clusters[x];
        while (tmp != x) {
            int next = clusters[tmp];
            clusters[tmp] = x;
            tmp = next;
        }
        return x;
    }

    void clusterUnion(int a, int b)
    {
        int aRoot = getRoot(a), bRoot = getRoot(b);
        clusters[aRoot] = bRoot;
    }
};

int main(void)
{
    Solution s;
    s.printClusters();
    return 0;
}
