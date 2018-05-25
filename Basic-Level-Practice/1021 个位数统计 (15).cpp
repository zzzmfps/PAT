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
    int counts[10] = {};
    string num;
    getline(cin, num);
    for (auto n : num) ++counts[n - '0'];
    bool isNotFirstLine = false;
    for (int i = 0; i < 10; ++i)
        if (counts[i] != 0) {
            if (isNotFirstLine)
                cout << '\n';
            else
                isNotFirstLine = true;
            cout << i << ":" << counts[i];
        }
    // cout<< '\b'; can delete last output character, but not include '\n'.
    system("pause");
    return 0;
}
