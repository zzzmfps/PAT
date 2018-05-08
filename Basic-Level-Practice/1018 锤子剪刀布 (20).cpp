#include <iostream>
#include <unordered_map>

static int x = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    using namespace std;

    auto check = [](char a, char b) {
        if (a == b) return -1;
        if (a == 'C' && b == 'J' || a == 'J' && b == 'B' || a == 'B' && b == 'C') return 0;
        return 1;
    };
    auto print_max = [](unordered_map<char, int> &m) {
        int tmp = max(max(m['B'], m['C']), m['J']);
        tmp == m['B'] ? cout << 'B' : tmp == m['C'] ? cout << 'C' : cout << 'J';
    };
    unordered_map<char, int> record[2];
    int n;
    cin >> n;
    int n_tmp = n;
    char a, b;

    while (n_tmp--) {
        cin >> a >> b;
        int win = check(a, b);
        if (win < 0) continue;
        record[win][0] += 1;
        record[win][win ? b : a] += 1;
    }
    int ties = n - record[0][0] - record[1][0];
    cout << record[0][0] << ' ' << ties << ' ' << record[1][0] << '\n';
    cout << record[1][0] << ' ' << ties << ' ' << record[0][0] << '\n';
    print_max(record[0]);
    cout << ' ';
    print_max(record[1]);

    system("pause");
    return 0;
}
