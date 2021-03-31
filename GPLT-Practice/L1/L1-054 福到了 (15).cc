#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    char x;
    int n;
    cin >> x >> n;
    vector<vector<char>> word(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        cin.get();
        for (int j = 0; j < n; ++j) word[i][j] = cin.get();
    }
    // check
    bool isSame = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (word[i][j] == word[n - i - 1][n - j - 1]) continue;
            isSame = false;
            break;
        }
        if (!isSame) break;
    }
    // print
    if (isSame) cout << "bu yong dao le\n";
    for (int i = n - 1; i > -1; --i)
        for (int j = n - 1; j > -1; --j) cout << (word[i][j] == ' ' ? ' ' : x) << (j ? "" : "\n");
    return 0;
}
