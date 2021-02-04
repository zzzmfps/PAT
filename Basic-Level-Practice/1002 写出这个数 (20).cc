#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

static const string digits[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main(void)
{
    string num;
    getline(cin, num);
    int sum = 0;
    for (auto n : num) sum += n - '0';
    num = to_string(sum);
    for (int i = 0; i < num.size() - 1; ++i) cout << digits[num[i] - '0'] << ' ';
    cout << digits[num.back() - '0'];
    // cout<< '\b'; get correct output but fails on PTA.
    system("pause");
    return 0;
}
