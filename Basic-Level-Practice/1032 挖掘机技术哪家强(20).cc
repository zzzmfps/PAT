#include <iostream>
#include <unordered_map>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main(void)
{
    int n, index, score, max_index = 0, max_score = 0;
    unordered_map<int, int> record;
    cin >> n;
    while (n--) {
        cin >> index >> score;
        record[index] += score;
        if (record[index] > max_score) {
            max_index = index;
            max_score = record[index];
        }
    }
    cout << max_index << ' ' << max_score;
    system("pause");
    return 0;
}
