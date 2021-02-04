#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    int n, length = 256, i;
    (cin >> n).get();
    string *sentences = new string[n];
    for (int i = 0; i < n; ++i) {
        if (cin.peek() == '\n') {
            cout << "nai";
            cin.get();
            cin.get();
            return 0;
        }
        getline(cin, sentences[i]);
        reverse(sentences[i].begin(), sentences[i].end());
        length = sentences[i].size() < length ? sentences[i].size() : length;
    }
    for (i = 0; i < length; ++i)
        for (int j = 1; j < n; ++j)
            if (sentences[0][i] != sentences[j][i]) {
                if (i == 0 || i == 1 && sentences[0][0] == ' ') {
                    cout << "nai";
                } else {
                    if (sentences[0][i - 1] == ' ') i -= 1;
                    cout << string(sentences[0].rend() - i, sentences[0].rend());
                }
                i = 256;
                break;
            }

    if (i == length) cout << string(sentences[0].rend() - i, sentences[0].rend());
    cin.get();
    return 0;
}
