#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution
{
private:
    const int LIMIT = 100000;
    int head, num, k;
    unordered_map<int, pair<int, int>> link;

public:
    Solution()
    {
        cin >> head >> num >> k;
        for (int i = 0; i < num; ++i) {
            int cur, val, next;
            cin >> cur >> val >> next;
            link[cur] = make_pair(val, next);
        }
        link[LIMIT] = make_pair(0, head);
    }

    void rearrange()
    {
        int idNotNegative = LIMIT, idGreaterThanK = -1;
        for (int l = LIMIT, i = head; i != -1; i = link[l].second) {
            auto &cur = link[i];
            if (cur.first > k) {
                l = i;
            } else if (cur.first < 0) {
                if (link[idNotNegative].second != i) {
                    link[l].second = cur.second;
                    cur.second = link[idNotNegative].second;
                    link[idNotNegative].second = i;
                } else {
                    l = i;
                }
                idNotNegative = i;
            } else {
                if (idGreaterThanK < 0) idGreaterThanK = idNotNegative;
                if (link[idGreaterThanK].second != i) {
                    link[l].second = cur.second;
                    cur.second = link[idGreaterThanK].second;
                    link[idGreaterThanK].second = i;
                } else {
                    l = i;
                }
                idGreaterThanK = i;
            }
        }
        for (int i = link[LIMIT].second; true; i = link[i].second) {
            cout << setw(5) << setfill('0') << i << ' ' << link[i].first << ' ';
            if (link[i].second == -1) {
                cout << -1;
                break;
            }
            cout << setw(5) << setfill('0') << link[i].second << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.rearrange();
    return 0;
}
