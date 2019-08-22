#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution
{
private:
    int n, m, threshold;
    int **arr;
    unordered_map<int, vector<int>> counts;
    int delta[2][8] = { {-1, -1, -1, 0, 0, 1, 1, 1}, {-1, 0, 1, -1, 1, -1, 0, 1} };

public:
    Solution()
    {
        cin >> m >> n >> threshold;
        arr = new int *[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[m];
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j];
                auto &x = counts[arr[i][j]];
                if (x.empty()) {
                    x.resize(3);
                    x[1] = i, x[2] = j;
                }
                x[0] += 1;
            }
        }
    }

    ~Solution()
    {
        for (int i = 0; i < n; ++i) delete[] arr[i];
        delete[] arr;
    }

    void findPixel()
    {
        int i, j, val;
        bool flag = false;
        for (const auto &p : counts) {
            int v = p.first, c = p.second[0], x = p.second[1], y = p.second[2];
            if (c > 1) continue;
            bool tmp = check(x, y, v);
            if (tmp) {
                if (flag) {
                    cout << "Not Unique";
                    return;
                }
                flag = tmp, i = x, j = y, val = v;
            }
        }
        if (flag) {
            cout << '(' << j + 1 << ", " << i + 1 << "): " << val;

        } else {
            cout << "Not Exist";
        }
    }

private:
    bool check(int x, int y, int v)
    {
        for (int i = 0; i < 8; ++i) {
            int xx = x + delta[0][i];
            int yy = y + delta[1][i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && abs(v - arr[xx][yy]) <= threshold) return false;
        }
        return true;
    }
};


int main(void)
{
    Solution s;
    s.findPixel();
    return 0;
}
