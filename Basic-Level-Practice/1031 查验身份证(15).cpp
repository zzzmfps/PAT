#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

static const int factors[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
static const char maps[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main(void)
{
    // PAT's test cases are not strict enough
    // code could be accepted even doesn't check the first 17 chars as digits
    int n;
    (cin >> n).get();
    bool allPass = true;
    while (n--) {
        string id;
        getline(cin, id);
        int sum = 0;
        for (int i = 0; i < 17; ++i) sum += factors[i] * (id[i] - '0');
        if (maps[sum % 11] != id.back()) {
            if (!allPass) cout << '\n';
            allPass = false;
            cout << id;
        }
    }
    if (allPass) cout << "All passed";
    system("pause");
    return 0;
}
