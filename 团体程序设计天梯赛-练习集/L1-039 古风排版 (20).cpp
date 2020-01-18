#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    int row;
    (cin >> row).get();
    string str;
    getline(cin, str);
    int col = ceil(str.size() / double(row));

    vector<vector<char>> mat(row, vector<char>(col, ' '));
    int i = 0, j = col - 1;
    for (auto c : str) {
        mat[i++][j] = c;
        if (i == row) i = 0, --j;
    }

    for (auto &v : mat) {
        for (auto c : v) cout << c;
        cout << '\n';
    }

    return 0;
}
