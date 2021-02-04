#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

static const string en[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(void)
{
    int sum = 0;
    while (cin.peek() != '\n') sum += cin.get() - 48;
    string snum = to_string(sum);
    cout << en[snum[0] - 48];
    for (int i = 1; i < snum.size(); ++i) cout << ' ' << en[snum[i] - 48];
    system("pause");
    return 0;
}
