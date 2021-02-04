#include <iostream>
#include <string>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    vector<string> words;
    string tmp;
    while (cin.peek() != '\n') {
        cin >> tmp;
        words.push_back(tmp);
    }
    cout << words.back();
    for (int i = words.size() - 2; i > -1; --i) cout << ' ' << words[i];
    system("pause");
    return 0;
}
