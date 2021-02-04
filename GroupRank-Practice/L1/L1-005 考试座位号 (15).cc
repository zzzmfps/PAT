#include <iostream>
#include <utility>
using namespace std;

class Solution
{
private:
    typedef long long ll;
    pair<ll, short> *record;

public:
    Solution()
    {
        short n;
        cin >> n;
        record = new pair<ll, short>[n + 1];
        while (n--) {
            ll idx;
            short s1, s2;
            cin >> idx >> s1 >> s2;
            record[s1] = make_pair(idx, s2);
        }
    }

    ~Solution()
    {
        delete[] record;
    }

    void query()
    {
        short m, s;
        cin >> m;
        while (m--) {
            cin >> s;
            cout << record[s].first << ' ' << record[s].second << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.query();
    return 0;
}
