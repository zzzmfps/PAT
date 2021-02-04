#include <iostream>
using namespace std;

void completeMatrix(int matrix[4][4]) {
    int val = 45, x = 0, y = 0;
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            if (0 == matrix[i][j]) {
                x = i, y = j;
            } else {
                val -= matrix[i][j];
            }
        }
    }
    matrix[x][y] = val;
}

int getCoins(int matrix[4][4], int direc) {
    int sum = 0;
    if (direc < 4) {
        sum = matrix[direc][1] + matrix[direc][2] + matrix[direc][3];
    } else if (direc < 7) {
        sum = matrix[1][direc - 3] + matrix[2][direc - 3] + matrix[3][direc - 3];
    } else if (direc == 7) {
        sum = matrix[1][1] + matrix[2][2] + matrix[3][3];
    } else {
        sum = matrix[1][3] + matrix[2][2] + matrix[3][1];
    }
    int coins[] = {10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600};
    return coins[sum - 6];
}

int main(void) {
    int matrix[4][4], row, col, choose;
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            cin >> matrix[i][j];
        }
    }
    completeMatrix(matrix);
    for (int i = 0; i < 3; ++i) {
        cin >> row >> col;
        cout << matrix[row][col] << '\n';
    }
    cin >> choose;
    cout << getCoins(matrix, choose);
    return 0;
}
