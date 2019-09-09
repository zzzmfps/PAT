#include <iostream>
using namespace std;

class Solution
{
public:
    void eulerianPath()
    {
        int n, m;
        cin >> n >> m;
        int *degrees = new int[n + 1] {};
        int *unionSet = new int[n + 1]; // whether is it a connected graph
        for (int i = 1; i <= n; ++i) unionSet[i] = i;
        while (m--) {
            int a, b;
            cin >> a >> b;
            ++degrees[a];
            ++degrees[b];
            join(unionSet, a, b);
        }

        int count = 0, type;
        for (int i = 1; i <= n; ++i) {
            if (degrees[i] > 0) {
                type = findRoot(unionSet, i);
                break;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (degrees[i] > 0) {
                if (type != findRoot(unionSet, i)) count = 3;
                if (degrees[i] & 1) ++count;
            }
            if (i > 1) cout << ' ';
            cout << degrees[i];
        }
        delete[] degrees;
        delete[] unionSet;
        cout << '\n';
        cout << (count == 0 ? "Eulerian" : count == 2 ? "Semi-Eulerian" : "Non-Eulerian");
    }

private:
    int findRoot(int *list, int x)
    {
        int tmp = x;
        while (x != list[x]) x = list[x];
        while (tmp != x) {
            int tmp2 = list[tmp];
            list[tmp] = x;
            tmp = tmp2;
        }
        return x;
    }

    void join(int *list, int x, int y)
    {
        int xx = findRoot(list, x), yy = findRoot(list, y);
        list[xx] = yy;
    }
};

int main(void)
{
    Solution s;
    s.eulerianPath();
    return 0;
}
