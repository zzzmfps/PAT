#include <iostream>
using namespace std;

int main(void)
{
    int col;
    char ch;
    cin >> col >> ch;
    int row = int(0.5 + 0.5 * col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) cout << ch;
        cout << '\n';
    }
    return 0;
}
