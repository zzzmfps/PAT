#include <algorithm>
#include <cmath>
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
    int num, *seq;
    int row, col, **mat;

  public:
    Solution()
    {
        cin >> num;

        seq = new int[num];
        for (int i = 0; i < num; ++i) cin >> seq[i];
        sort(seq, seq + num, greater<int>());

        col = int(sqrt(num));
        while (true) {
            if (num % col == 0) break;
            --col;
        }
        row = num / col;
        mat = new int *[row];
        for (int i = 0; i < row; ++i) mat[i] = new int[col];
    }

    ~Solution()
    {
        for (int i = 0; i < row; ++i) delete[] mat[i];
        delete[] seq, mat;
    }

    void printSpiralMatrix()
    {
        int u = 0, d = row - 1, l = 0, r = col - 1, idx = 0;
        while (true) {
            for (int i = l; i <= r; ++i) mat[u][i] = seq[idx++];
            if (u++ == d) break;
            for (int i = u; i <= d; ++i) mat[i][r] = seq[idx++];
            if (r-- == l) break;
            for (int i = r; i >= l; --i) mat[d][i] = seq[idx++];
            if (d-- == u) break;
            for (int i = d; i >= u; --i) mat[i][l] = seq[idx++];
            if (l++ == r) break;
        }
        for (int i = 0; i < row; ++i) {
            cout << mat[i][0];
            for (int j = 1; j < col; ++j) cout << ' ' << mat[i][j];
            cout << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.printSpiralMatrix();
    return 0;
}
