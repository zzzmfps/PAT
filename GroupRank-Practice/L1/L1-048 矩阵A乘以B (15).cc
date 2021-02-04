#include <iostream>
#include <vector>
using namespace std;

void getMatrix(vector<vector<int>> &mat)
{
    int row = mat.size(), col = mat[0].size();
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j) cin >> mat[i][j];
}

int main(void)
{
    int row1, col1, row2, col2;
    cin >> row1 >> col1;
    vector<vector<int>> mat1(row1, vector<int>(col1));
    getMatrix(mat1);
    cin >> row2 >> col2;
    if (col1 != row2) {
        cout << "Error: " << col1 << " != " << row2;
        cin.get(); // option: ignore remaining input chars
        while (row2--) cin.ignore(5 * col2, '\n');
    } else {
        vector<vector<int>> mat2(row2, vector<int>(col2));
        getMatrix(mat2);
        cout << row1 << ' ' << col2 << '\n';
        for (int i = 0; i < row1; ++i) {
            for (int j = 0; j < col2; ++j) {
                int tmp = 0;
                for (int k = 0; k < col1; ++k) tmp += mat1[i][k] * mat2[k][j];
                cout << tmp << (j + 1 == col2 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
