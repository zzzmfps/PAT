#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void recommendationSystem()
    {
        int n, k;
        cin >> n >> k;
        int *count = new int[n + 1] {};
        vector<int> rec;
        rec.reserve(k);
        auto sortRule = [count](int x, int y) {
            return count[x] > count[y] || count[x] == count[y] && x < y;
        };

        int x;
        cin >> x;
        count[x] = 1;
        rec.push_back(x);
        for (int i = 1; i < n; ++i) {
            cin >> x;
            cout << x << ':';
            for (auto r : rec) cout << ' ' << r;
            cout << '\n';
            count[x] += 1;
            auto it = find(rec.begin(), rec.end(), x);
            if (it == rec.end()) rec.push_back(x);
            sort(rec.begin(), rec.end(), sortRule);
            rec.resize(min(k, int(rec.size())));
        }
        delete[] count;
    }
};

int main(void)
{
    Solution s;
    s.recommendationSystem();
    return 0;
}
