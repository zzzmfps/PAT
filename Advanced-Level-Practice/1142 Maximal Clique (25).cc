#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    void maximalClique()
    {
        int nv, ne;
        cin >> nv >> ne;
        vector<vector<bool>> mat(nv + 1);
        for (int i = 1; i <= nv; ++i) mat[i].resize(nv + 1);

        int x, y;
        while (ne--) {
            cin >> x >> y;
            mat[x][y] = mat[y][x] = true;
        }

        int k, m, v;
        cin >> k;
        while (k--) {
            cin >> m;
            unordered_set<int> tmp;
            while (m--) {
                cin >> v;
                tmp.insert(v);
            }
            switch (check(mat, tmp)) {
                case 0: cout << "Not a Clique\n"; break;
                case 1: cout << "Not Maximal\n"; break;
                case 2: cout << "Yes\n"; break;
            }
        }
    }

private:
    int check(const vector<vector<bool>> &mat, const unordered_set<int> &t)
    {
        for (auto v : t) {
            for (auto v2 : t) {
                if (v == v2) continue;
                if (!mat[v][v2]) return 0;
            }
        }
        for (int i = 1, n = mat.size(); i < n; ++i) {
            if (t.find(i) != t.end()) continue;
            bool flag = true;
            for (auto v2 : t) {
                if (!mat[i][v2]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return 1;
        }
        return 2;
    }
};


int main(void)
{
    Solution s;
    s.maximalClique();
    return 0;
}
